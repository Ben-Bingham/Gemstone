#pragma once

#include "Collider.h"

namespace Pyrite {
	using namespace Literals;
	class AxisAlignedBoxCollider : public Collider {
	public:
		AxisAlignedBoxCollider(Point3D min = Point3D{ 0.0_m }, Point3D max = Point3D{ 1.0_m });

		Collision collidesWith(const Collider* collider) const override;
		Collision collidesWithAABB(const AxisAlignedBoxCollider* box) const override;
		Collision collidesWithSphere(const SphereCollider* sphere) const override;

		Point3D getDimensions() const;

		Point3D min;
		Point3D max;
	};
}