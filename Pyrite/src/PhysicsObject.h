#pragma once

#include "Units.h"

namespace Pyrite {
	using namespace Literals;

	class PhysicsObject {
	public:
		PhysicsObject(Kilogram Mass, Position3D pos) 
			: mass(Mass), position(pos) {
		}

		virtual void calcNetForce() {
			netForce = 0;
		}

	protected:
		Kilogram mass;
		Position3D position;
		Newton3D netForce{ 0.0_N };
		Velocity velocity{ 0.0_m / 0.0_s };
	};
}