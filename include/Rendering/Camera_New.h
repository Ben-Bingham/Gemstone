#pragma once
#include "Math/Matrix.h"

namespace Gem {
	// Component;
	class Camera_New {
	public:
		Camera_New() = default;

		float fov{ 60 };
		Vector3f forward{ Vector3f::north };
	};
}