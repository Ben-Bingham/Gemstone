#pragma once
#include <cmath>
#include "Gem.h"

namespace Gem {
	template<typename T, typename G>
	GEM_API constexpr inline T ee(T val, G power) {
		return val * static_cast<T>(pow(static_cast<T>(10), static_cast<T>(power)));
	}
}