#pragma once

#include "Collider.h"

namespace Pyrite {
	class SphereCollider : public Collider {
	public:
		SphereCollider(Meter radius = Meter{ 1.0_m }, Point3D origin = Point3D{ 0.0_m });

		Collision collidesWith(const Collider* collider) const override;
		Collision collidesWithAABB(const AxisAlignedBoxCollider* box) const override;
		Collision collidesWithSphere(const SphereCollider* sphere) const override;

		Meter radius;
	};
}