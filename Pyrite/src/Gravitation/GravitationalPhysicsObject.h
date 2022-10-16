#pragma once

#include <vector>

#include "PhysicsObject.h"
#include "Powers.h"

namespace Pyrite {
	const float gravitationalConstant = Malachite::ee(6.67430f, -11.0f);

	using namespace Literals;

	class GravitationalPhysicsObject : public PhysicsObject {
	public:
		GravitationalPhysicsObject(Meter Radius, Kilogram Mass, Position3D Pos = Position3D{ 0.0_m }, Velocity Velocity = Velocity{ 0.0_mPerS })
			: PhysicsObject(Mass, Pos, Velocity), radius(Radius) {

		}

		GravitationalField getGravitationalField(Meter distanceFromSurface) const {
			Meter distance = radius + distanceFromSurface;
			return (GravitationalField)(gravitationalConstant * mass) / (distance * distance);
		}

		Newton getGravitationalForce(const GravitationalPhysicsObject& obj) const {
			Displacement displacementBetween = position - obj.position;
			Meter distanceBetween = displacementBetween.length();
			return (Newton)(gravitationalConstant * mass * obj.mass) / (distanceBetween * distanceBetween);
		}

		void calcNetForce(std::vector<GravitationalPhysicsObject*> interactingObjects) {
			netForce = Newton3D{ 0.0_N };
			for (GravitationalPhysicsObject* obj : interactingObjects) {
				netForce += getGravitationalForce(*obj);
			}
		}

		/*void calcPosition(std::vector<GravitationalPhysicsObject*> interactingObjects, Second timeSinceLastMovement) {
			calcNetForce(interactingObjects);
			
			Velocity initialVelocity = velocity;
			Acceleration3D acceleration = (netForce / mass);
			velocity = acceleration * timeSinceLastMovement + initialVelocity;

			Displacement displacement = ((initialVelocity) * (initialVelocity - velocity * velocity)) / 2.0f * acceleration;

			position += displacement;
		}*/

	private:
		Meter radius;
	};
}