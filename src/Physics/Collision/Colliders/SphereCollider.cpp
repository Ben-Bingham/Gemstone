#include "pch.h"
#include "Physics/Collision/Colliders/SphereCollider.h"
#include "Physics/Collision/CollisionDetection.h"

namespace Gem {
	SphereCollider::SphereCollider(Meter Radius, Point3D Origin) 
		: radius(Radius), Collider(Origin) {

	}

	Collider::Collision SphereCollider::collidesWith(const Collider* collider) const {
		return collider->collidesWithSphere(this);
	}

	Collider::Collision SphereCollider::collidesWithAABB(const AxisAlignedBoxCollider* box) const {
		return CollisionDetection::AABBWithSphere(box, this);
	}

	Collider::Collision SphereCollider::collidesWithSphere(const SphereCollider* sphere) const {
		return CollisionDetection::SphereWithSphere(sphere, this);
	}
}