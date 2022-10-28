#pragma once

#include <algorithm>

namespace Malachite {
	template<typename T, typename G>
	T clamp(T value, G min, G max) {
		return std::max(static_cast<T>(min), std::min(static_cast<T>(max), value));
	}
}