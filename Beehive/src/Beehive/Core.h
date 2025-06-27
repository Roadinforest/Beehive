#pragma once



#ifdef BH_PLATFORM_WINDOWS
	#ifdef BH_BUILD_DLL
		#define BH_API __declspec(dllexport)
	#else
		#define BH_API __declspec(dllimport)
	#endif

#else
	#error Beehive engine only supports Windows
#endif
