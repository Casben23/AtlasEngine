#pragma once


#ifdef AT_PLATFORM_WINDOWS
	#ifdef AT_BUILD_DLL
		#define AT_API __declspec(dllexport)
	#else
		#define AT_API __declspec(dllimport)
	#endif 
#endif 