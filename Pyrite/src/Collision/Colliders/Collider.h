#pragma once

#include "Units.h"

namespace Pyrite {
	class AxisAlignedBoxCollider;

	using namespace Literals;
	class Collider {
	public:
		Collider();

		struct Collision {
			Point3D localA{ 0.0_m };
			Point3D localB{ 0.0_m };
			Direction normal{ 0.0_m };
			Meter penetrationDistance{ 0.0_m };
		};

		virtual bool collidesWithAABB(const AxisAlignedBoxCollider* box) const = 0;
		virtual Collision AABBCollisionInfo(const AxisAlignedBoxCollider* box) const = 0;
	};
}