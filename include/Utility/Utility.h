#pragma once
#include <string>
#include <iostream>

namespace Gem {
	template<typename Arg1, typename ...Args> 
	void Print(Arg1&& arg, Args&&... args) { // Code made with help from ChatGPT
		if constexpr (sizeof...(Args) == 0) {
			std::cout << arg << std::endl;
		}
		else {
			std::cout << arg;
			if constexpr (sizeof...(Args) != 0) {
				std::cout << ", ";
			}
			Print(args...);
		}
	}

#ifdef GEM_DEBUG
#ifdef GEM_RELEASE
	static_assert(false, "Both Debug and release defined.");
#endif
#endif

#ifndef GEM_DEBUG
#ifndef GEM_RELEASE
	static_assert(false, "Neither Debug nor release are defined.");
#endif
#endif

#ifdef GEM_DEBUG
#define GEM_ASSERT(condition, msg) assert((condition), (msg))
#else
#define GEM_ASSERT 
#endif
}