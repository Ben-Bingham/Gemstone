#pragma once

#include "Colliders/AxisAlignedBoxCollider.h"

namespace Pyrite {
	namespace CollisionDetection {
		Collider::Collision AABBwithAABB(const AxisAlignedBoxCollider* box1, const AxisAlignedBoxCollider* box2);
	}
}