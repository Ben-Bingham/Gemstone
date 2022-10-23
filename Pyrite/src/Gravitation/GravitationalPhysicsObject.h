#pragma once

#include <vector>

#include "PhysicsObject.h"
#include "Powers.h"

namespace Pyrite {
	const float gravitationalConstant = Malachite::ee(6.67430f, -11.0f);

	using namespace Literals;

	class GravitationalPhysicsObject : public PhysicsObject {
	public:
		GravitationalPhysicsObject(Meter Radius, Kilogram Mass, Point3D Pos = Point3D{ 0.0_m }, Velocity Velocity = Velocity{ 0.0_mPerS })
			: PhysicsObject(Mass, Pos, Velocity), radius(Radius) {
		}

		GravitationalField getGravitationalField(Meter distanceFromSurface) const {
			Meter distance = radius + distanceFromSurface;
			return (GravitationalField)(gravitationalConstant * mass) / (distance * distance);
		}

		Newton3D getGravitationalForce(const PhysicsObject& obj) const {
			Displacement displacementBetween = position - obj.position;
			Meter distanceBetween = displacementBetween.length();
			Newton gravForce = (Newton)(gravitationalConstant * mass * obj.mass) / (distanceBetween * distanceBetween);

			Point3D direction;
			if (mass > obj.mass) {
				direction = position - obj.position;
			}
			else {
				direction = obj.position - position;
			}
			direction = direction.normalize();
			Newton3D gravFoce3D = gravForce * direction;
			return gravFoce3D;
		}

		void calcNetForce(std::vector<PhysicsObject*> interactingObjects) override {
			netForce = Newton3D{ 0.0_N };
			for (PhysicsObject* obj : interactingObjects) {
				netForce += getGravitationalForce(*obj);
			}
		}

		Meter radius;
	};
}