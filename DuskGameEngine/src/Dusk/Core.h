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

#define BIT(x) (x << 1)

#define DK_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)