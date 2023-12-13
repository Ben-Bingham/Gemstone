#pragma once
#include "Gem.h"

namespace Gem {
	template<typename T>
	bool EqualEnough(const T value1, const T value2, const T epsilon) {
		if (value1 + epsilon > value2 && value1 - epsilon < value2) {
			return true;
		}

		return false;
	}
}