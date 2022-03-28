#pragma once

#ifdef DK_PLATFORM_WINDOWS
	#ifdef DK_BUILD_DLL
		#define DUSK_API __declspec(dllexport)
	#else
		#define DUSK_API __declspec(dllimport)
	#endif
#else
	#error Dusk only supports Windows!
#endif