#pragma once
#include <cmath>

namespace Malachite {
	template<typename T, typename G>
	inline T ee(T val, G power) {
		return val * static_cast<T>(pow(static_cast<T>(10), static_cast<T>(power)));
	}
}