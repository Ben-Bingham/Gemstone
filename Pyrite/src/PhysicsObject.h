#pragma once

#include "Units.h"

namespace Pyrite {
	using namespace Literals;

	class PhysicsObject {
	public:
		PhysicsObject(Kilogram Mass, Position3D pos, Velocity Velocity = Velocity{ 0.0_mPerS })
			: mass(Mass), position(pos), velocity(Velocity) {

		}

		Position3D getPosition() const { return position; }
		
		void calcVelocity(Second deltaTime) {
			Velocity inititialVelocity = velocity;
			Acceleration3D acceleration = netForce / mass;

			//velocity = acceleration * deltaTime + inititialVelocity;
			velocity.x = (acceleration.x * deltaTime) + inititialVelocity.x;
			velocity.y = (acceleration.y * deltaTime) + inititialVelocity.y;
			velocity.z = (acceleration.z * deltaTime) + inititialVelocity.z;
		}

		void calcPosition(Second deltaTime) {
			Acceleration3D acceleration = netForce / mass;
			Position3D displacement = (velocity * deltaTime) + (0.5f * acceleration * (deltaTime * deltaTime));

			position += displacement;
		}

		Kilogram mass;
		Velocity velocity{ 0.0_mPerS };

	protected:
		Position3D position;
		Newton3D netForce{ 0.0_N };
	};
}