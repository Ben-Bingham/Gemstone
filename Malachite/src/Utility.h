#pragma once

#include <algorithm>

namespace Malachite {
	template<typename T, typename G>
	T clamp(T value, G min, G max) {
		return std::max(static_cast<T>(min), std::min(static_cast<T>(max), value));
	}

	template<typename T, typename G>
	T max(T val1, G val2) {
		return val1 > val2 ? val1 : val2;
	}

	template<typename T, typename G>
	T min(T val1, G val2) {
		return val1 < val2 ? val1 : val2;
	}
}