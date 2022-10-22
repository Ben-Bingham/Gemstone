#pragma once

#include "Units.h"
#include "Powers.h"

namespace Pyrite {
	using namespace Literals;

	class PhysicsObject {
	public:
		PhysicsObject(Kilogram Mass, Position3D pos, Velocity Velocity = Velocity{ 0.0_mPerS })
			: mass(Mass), position(pos), velocity(Velocity) {

		}

		Position3D getPosition() const { return position; }
		
		void calcVelocity(Second deltaTime) {
			velocity += (netForce / mass) * deltaTime;
		}

		void calcPosition(Second deltaTime) {
			position += velocity * deltaTime;
		}

		Kilogram mass;
		Velocity velocity{ 0.0_mPerS };

	protected:
		Position3D position;
		Newton3D netForce{ 0.0_N };
	};
}