#pragma once

#include "Collider.h"

namespace Pyrite {
	using namespace Literals;
	class BoxCollider : public Collider {
	public:
		BoxCollider(Point3D dimensions = Point3D{ 1.0_m }, Point3D position = Point3D{ 0.0_m });

		bool collidesWithBox(const BoxCollider* box) const override;

		Point3D dimensions;
	};
}