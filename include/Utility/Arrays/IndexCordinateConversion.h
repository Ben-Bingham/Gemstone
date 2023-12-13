#pragma once

#include "Vector.h"
#include "Gem.h"

namespace Gem {
	template<typename T>
	inline T twoDToIndex(Vector2<T> cord, T width) {
		return cord.x * width + cord.y;
	}

	template<typename T>
	inline Vector2<T> indexToTwoD(unsigned int index, T width) {
		return Vector2<T>{ index % width, index / width };
	}
}