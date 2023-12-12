#pragma once

#include "Constants.h"
#include "Gem.h"

namespace Gem {
	using Degree = float;
	using Radian = float;

	GEM_API inline Radian degreesToRadians(Degree degree) {
		return degree * (pi / 180.0f);
	}

	GEM_API inline Degree radiansToDegrees(Radian radian) {
		return radian * (180.0f / pi);
	}
}