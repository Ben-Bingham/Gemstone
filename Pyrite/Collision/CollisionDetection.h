#pragma once

#include "Colliders/AxisAlignedBoxCollider.h"
#include "Colliders/SphereCollider.h"

namespace Pyrite {
	namespace CollisionDetection {
		Collider::Collision AABBWithAABB(const AxisAlignedBoxCollider* box1, const AxisAlignedBoxCollider* box2);
		Collider::Collision AABBWithSphere(const AxisAlignedBoxCollider* box, const SphereCollider* sphere);
		Collider::Collision SphereWithSphere(const SphereCollider* sphere1, const SphereCollider* sphere2);
	}
}