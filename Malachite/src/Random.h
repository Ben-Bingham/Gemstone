#pragma once
#include <cstdlib>

namespace Malachite {
	template<typename T>
	T random() { // [0, 1[
		return std::rand() / (RAND_MAX + static_cast<T>(1));
	}

	template<typename T>
	T random(T min, T max) { // [min, max[
		return min + (max - min) * random<T>();
	}
}