#pragma once
#include <cmath>

namespace Malachite {
	template<typename T>
	inline T ee(T val, T power) { //TODO make a version where the power is not the same type as the main number
		return val * (T)pow(static_cast<T>(10), power);
	}
}