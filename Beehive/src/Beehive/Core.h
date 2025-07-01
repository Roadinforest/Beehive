#pragma once

#include <string>
#include <sstream>
#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <vector>
#include <unordered_map>
#include <unordered_set>


#ifdef BH_PLATFORM_WINDOWS
	#ifdef BH_BUILD_DLL
		#define BH_API __declspec(dllexport)
	#else
		#define BH_API __declspec(dllimport)
	#endif

#else
	#error Beehive engine only supports Windows
#endif

#define BIT(n) (1<<n)
