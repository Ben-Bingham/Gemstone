#pragma once
#include "Math/Vector.h"
#include "Gem.h"

namespace Gem::WindowEvents {
	struct GEM_API Resize {
		Vector2ui size{ 0 };
	};
}