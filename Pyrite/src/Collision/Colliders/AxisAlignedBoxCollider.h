#pragma once

#include "Collider.h"

namespace Pyrite {
	using namespace Literals;
	class AxisAlignedBoxCollider : public Collider {
	public:
		AxisAlignedBoxCollider(Point3D min = Point3D{ 0.0_m }, Point3D max = Point3D{ 1.0_m });

		bool collidesWithAABB(const AxisAlignedBoxCollider* box) const override;
		Collision AABBCollisionInfo(const AxisAlignedBoxCollider* box) const override;

		Point3D min;
		Point3D max;

		Point3D getOrigin() const;
	};
}