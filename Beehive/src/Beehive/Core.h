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

#ifdef BH_ENABLE_ASSERTS
	#define	BH_ASSERT(x,...) {if(!x){BH_ERROR("Assertion Failed: {0}",__VA_ARGS__);__debugbreak();}}
	#define BH_CORE_ASSERT(x, ...) { if(!(x)) { BH_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define BH_ASSERT(x, ...)
	#define BH_CORE_ASSERT(x, ...)
#endif

#define BIT(n) (1<<n)
