#pragma once
#include "Colliders/ColliderObject.h"

namespace Gem {
	bool Collide(ColliderObject colliderA, ColliderObject colliderB);

	bool FixedBoxFixedBox(const ColliderObject& colliderA, const ColliderObject& colliderB);
}