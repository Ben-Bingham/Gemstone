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
}