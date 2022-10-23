#pragma once

#include "Units.h"

namespace Pyrite {
	class BoxCollider;

	using namespace Literals;
	class Collider {
	public:
		Collider(Point3D position = Point3D{ 0.0_m });

		virtual bool collidesWithBox(const BoxCollider* box) const = 0;

		Point3D position;
	};
}