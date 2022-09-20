#pragma once

#include "Constants.h"

namespace Malachite {
	using Degree = float;
	using Radian = float;

	inline Radian degreesToRadians(Degree degree) {
		return degree * (pi / 180.0f);
	}

	inline Degree radiansToDegrees(Radian radian) {
		return radian * (180.0f / pi);
	}
}