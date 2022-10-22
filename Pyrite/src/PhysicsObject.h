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
		
		virtual void calcNetForce(std::vector<PhysicsObject*> interactingObjects) {
			netForce = Newton3D{ 0.0_N };
		}

		virtual void calcVelocity(Second deltaTime) {
			velocity += (netForce / mass) * deltaTime;
		}

		virtual void calcPosition(Second deltaTime) {
			position += velocity * deltaTime;
		}

		Kilogram mass;
		Velocity velocity{ 0.0_mPerS };
		Position3D position;
		Newton3D netForce{ 0.0_N };
	};
}