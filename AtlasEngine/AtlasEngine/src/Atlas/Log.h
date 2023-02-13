#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Atlas
{
	class AT_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
	};
}

//Core Log Macros
#define AT_CORE_ERROR(...)		::Atlas::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AT_CORE_INFO(...)		::Atlas::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AT_CORE_TRACE(...)		::Atlas::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AT_CORE_WARN(...)		::Atlas::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AT_CORE_FATAL(...)		::Atlas::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client Log Macros
#define AT_CLIENT_ERROR(...)	::Atlas::Log::GetClientLogger()->error(__VA_ARGS__)
#define AT_CLIENT_INFO(...)		::Atlas::Log::GetClientLogger()->info(__VA_ARGS__)
#define AT_CLIENT_TRACE(...)	::Atlas::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AT_CLIENT_WARN(...)		::Atlas::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AT_CLIENT_FATAL(...)	::Atlas::Log::GetClientLogger()->fatal(__VA_ARGS__)