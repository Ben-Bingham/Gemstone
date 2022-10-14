#pragma once

#include "Units.h"

namespace Pyrite {
	using namespace Literals;

	class PhysicsObject {
	public:
		PhysicsObject(Kilogram Mass, Position3D pos, Velocity velocity = Velocity{ 0.0_mPerS })
			: mass(Mass), position(pos) {
		}

		virtual void calcNetForce() {
			netForce = 0;
		}

		Position3D getPosition() const { return position; }

	protected:
		Kilogram mass;
		Position3D position;
		Newton3D netForce{ 0.0_N };
		Velocity velocity{ 0.0_mPerS };
	};
}