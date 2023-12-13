#pragma once

#include <algorithm>
#include "Gem.h"

namespace Gem {
	template<typename T, typename G>
	GEM_API T clamp(T value, G min, G max) {
		return std::max(static_cast<T>(min), std::min(static_cast<T>(max), value));
	}

	template<typename T, typename G>
	GEM_API T max(T val1, G val2) {
		return val1 > val2 ? val1 : val2;
	}

	template<typename T, typename G>
	GEM_API T min(T val1, G val2) {
		return val1 < val2 ? val1 : val2;
	}
}