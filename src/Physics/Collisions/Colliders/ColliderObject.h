#pragma once
#include "Collider.h"
#include "Utility/Transform.h"

namespace Gem {
	struct ColliderObject {
		Ptr<BaseCollider> collider;
		Transform transform;
	};
}