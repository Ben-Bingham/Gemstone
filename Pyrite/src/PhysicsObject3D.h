#pragma once

#include "PhysicsObject.h"

#include "Vector.h"

namespace Pyrite {
	using namespace Literals;
	using Position3D = Malachite::Vector3<Meter>;

	class PhysicsObject3D : public PhysicsObject {
	public:
		PhysicsObject3D(Kilogram mass, Position3D pos = Position3D{ 0.0_m })
			: PhysicsObject(mass), position(pos) {

		}

	protected:
		Position3D position;
	};
}