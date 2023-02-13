workspace "Atlas"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "AtlasEngine"
	location "AtlasEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "atpch.h"
	pchsource "AtlasEngine/src/atpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"AT_PLATFORM_WINDOWS",
			"AT_BUILD_DLL",
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "AT_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AT_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "AT_DIST"
		optimize "On"
		
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"AtlasEngine/vendor/spdlog/include",
		"AtlasEngine/src"
	}

	links
	{
		"AtlasEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"AT_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "AT_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AT_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "AT_DIST"
		optimize "On"