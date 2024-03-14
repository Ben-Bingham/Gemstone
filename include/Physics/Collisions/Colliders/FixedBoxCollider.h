#pragma once
#include "BaseCollider.h"

#include "Math/Vector.h"

namespace Gem {
	class FixedBoxCollider : public BaseCollider {
	public:
		FixedBoxCollider();

		Vector3f minDistances{ -1.0f, -1.0f, -1.0f };
		Vector3f maxDistances{ 1.0f, 1.0f, 1.0f };
	};
}