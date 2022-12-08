#pragma once

#include "Vector.h"

namespace Malachite {
	// unsigned int -> unsigned short + unsigned short
	inline unsigned int concatenate(unsigned short leftVal, unsigned short rightVal) {
		return ((unsigned int)leftVal << 16) | rightVal;
	}

	inline Vector2<unsigned short> split(unsigned int val) {
		Vector2<unsigned short> result;

		unsigned short newRight = val & 0xFFFF;
		unsigned short newLeft = (val >> 16) & 0xFFFF;

		result.x = newLeft;
		result.y = newRight;

		return result;
	}

	// unsigned short -> unsigned char + unsigned char
	inline unsigned short concatenate(unsigned char val1, unsigned char val2) {
		return ((unsigned short)val1 << 8) | val2;
	}

	inline Vector2<unsigned char> split(unsigned short val) {
		Vector2<unsigned char> result;

		unsigned char newRight = val & 0xFF;
		unsigned char newLeft = (val >> 8) & 0xFF;

		result.x = newLeft;
		result.y = newRight;

		return result;
	}
}