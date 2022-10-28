#pragma once

#include "Units.h"

namespace Pyrite {
	class AxisAlignedBoxCollider;

	using namespace Literals;
	class Collider {
	public:
		Collider();

		struct Collision {
			Point3D localA{ 0.0_m }; // Furthest point of A into B
			Point3D localB{ 0.0_m }; // Furthest point of B into A
			Direction normal{ 0.0_m }; // localA - localB normalized	// TODO consider removing
			Meter depth{ 0.0_m }; // Length of localA - localB			// TODO consider removing
			bool hasCollision;
		};

		virtual Collision collidesWithAABB(const AxisAlignedBoxCollider* box) const = 0;
	};
}