#pragma once

#include "Units.h"

namespace Pyrite {
	using namespace Literals;

	class PhysicsObject {
	public:
		PhysicsObject(Kilogram Mass, Position3D pos, Velocity Velocity = Velocity{ 0.0_mPerS })
			: mass(Mass), position(pos), velocity(Velocity) {

		}
		
		virtual void calcNetForce() {
			netForce = 0;
		}

		Position3D getPosition() const { return position; }

		void calcPosition(Second deltaTime) {
			Acceleration3D acceleration = netForce / mass;
			//Position3D displacement = (velocity * deltaTime) + (0.5f * acceleration * (deltaTime * deltaTime));
			Position3D displacement{ 0.0_m };
			displacement.x = (velocity.x * deltaTime) + (0.5f * acceleration.x * (deltaTime * deltaTime));
			displacement.y = (velocity.y * deltaTime) + (0.5f * acceleration.y * (deltaTime * deltaTime));
			displacement.z = (velocity.z * deltaTime) + (0.5f * acceleration.z * (deltaTime * deltaTime));

			position += displacement;
		}

		Kilogram mass;
		Velocity velocity{ 0.0_mPerS };

	protected:
		Position3D position;
		Newton3D netForce{ 0.0_N };
	};
}