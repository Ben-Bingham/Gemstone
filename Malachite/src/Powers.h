#pragma once
#include <cmath>

namespace Malachite {
	template<typename T>
	inline T ee(T val, T power) {
		return val * (T)pow(static_cast<T>(10), power);
	}
}