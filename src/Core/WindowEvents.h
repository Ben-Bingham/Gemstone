#pragma once
#include "Math/Vector.h"
#include "Gem.h"

namespace Gem::WindowEvents {
	struct Resize {
		glm::ivec2 size{ 0 };
	};
}