#pragma once
#include "Gem.h"

namespace Gem {
	template<typename T, size_t Size>
	GEM_API T RollingAverage(std::array<T, Size> list) {
		T total{ (T)0 };

		for (auto val : list) {
			total += val;
		}

		return total / list.size();
	}

	template<typename T>
	GEM_API T RollingAverage(std::vector<T> list) {
		T total{ (T)0 };

		for (auto val : list) {
			total += val;
		}

		return total / list.size();
	}
}