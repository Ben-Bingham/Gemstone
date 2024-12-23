#pragma once
#include "Math/Vector.h"

namespace Gem {
	// Component
	struct PhysicalProperties {
		Vector3f velocity{ 0.0f };
		Vector3f acceleration{ 0.0f };
		Vector3f netForce{ 0.0f };
		float mass{ 1.0f };
	};
}