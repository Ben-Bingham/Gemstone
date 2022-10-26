#pragma once

#include "Colliders/AxisAlignedBoxCollider.h"

namespace Pyrite {
	namespace CollisionDetection {
		bool boxWithBox(const AxisAlignedBoxCollider* box1, const AxisAlignedBoxCollider* box2);
		Collider::Collision boxWithBoxInfo(const AxisAlignedBoxCollider* box1, const AxisAlignedBoxCollider* box2);
	}
}