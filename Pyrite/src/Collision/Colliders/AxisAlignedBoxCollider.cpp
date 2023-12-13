#include "AxisAlignedBoxCollider.h"
#include "Collision/CollisionDetection.h"

namespace Pyrite {
	AxisAlignedBoxCollider::AxisAlignedBoxCollider(Point3D Min, Point3D Max)
		: min(Min), max(Max), Collider(min + (getDimensions() / 2.0_m)) {

	}

	Collider::Collision AxisAlignedBoxCollider::collidesWith(const Collider* collider) const {
		return collider->collidesWithAABB(this);
	}

	Collider::Collision AxisAlignedBoxCollider::collidesWithAABB(const AxisAlignedBoxCollider* box) const {
		return CollisionDetection::AABBWithAABB(this, box);
	}

	Collider::Collision AxisAlignedBoxCollider::collidesWithSphere(const SphereCollider* sphere) const {
		return CollisionDetection::AABBWithSphere(this, sphere);
	}

	Point3D AxisAlignedBoxCollider::getDimensions() const {
		return max - min;
	}
}