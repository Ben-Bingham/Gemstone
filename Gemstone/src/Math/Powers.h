#pragma once
#include <cmath>

namespace Gem {
	template<typename T, typename G>
	constexpr inline T ee(T val, G power) {
		return val * static_cast<T>(pow(static_cast<T>(10), static_cast<T>(power)));
	}
}