#include "AxisAlignedBoxCollider.h"
#include "Collision/CollisionDetection.h"

namespace Pyrite {
	AxisAlignedBoxCollider::AxisAlignedBoxCollider(Point3D Min, Point3D Max)
		: min(Min), max(Max) {

	}

	Collider::Collision AxisAlignedBoxCollider::collidesWithAABB(const AxisAlignedBoxCollider* box) const {
		return CollisionDetection::AABBwithAABB(this, box);
	}

	Point3D AxisAlignedBoxCollider::getOrigin() const {
		return min + (getDimensions() / 2.0_m);
	}

	Point3D AxisAlignedBoxCollider::getDimensions() const {
		return max - min;
	}
}