#include "AxisAlignedBoxCollider.h"
#include "Collision/CollisionDetection.h"

namespace Pyrite {
	AxisAlignedBoxCollider::AxisAlignedBoxCollider(Point3D Min, Point3D Max)
		: min(Min), max(Max) {

	}

	bool AxisAlignedBoxCollider::collidesWithAABB(const AxisAlignedBoxCollider* box) const {
		return CollisionDetection::boxWithBox(this, box);
	}

	Collider::Collision AxisAlignedBoxCollider::AABBCollisionInfo(const AxisAlignedBoxCollider* box) const {
		return CollisionDetection::boxWithBoxInfo(this, box);
	}

	Point3D AxisAlignedBoxCollider::getOrigin() const {
		return (max - min) / 2.0_m;
	}
}