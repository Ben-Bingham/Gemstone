#pragma once

#include "PhysicsObject3D.h"

namespace Pyrite {
	const float gravitationalConstant = ee(6.67430, -11);

	class GravitationalPhysicsObject : public PhysicsObject3D {
	public:
		GravitationalPhysicsObject(Meter Radius, Kilogram Mass, Position3D Pos = Position3D{ 0.0_m })
			: PhysicsObject3D(Mass, Pos), radius(Radius) {

		}

		GravitationalField getGravitationalField(Meter distanceFromSurface) const {
			Meter distance = radius + distanceFromSurface;
			return (GravitationalField)(gravitationalConstant * mass) / (distance * distance);
		}

		Newton getGravitationalForce(const GravitationalPhysicsObject& obj, Meter distanceBetweenSurfaces) const {
			Meter distanceBetween = radius + distanceBetweenSurfaces + obj.radius;
			return (Newton)(gravitationalConstant * mass * obj.mass) / (distanceBetween * distanceBetween);
		}

	private:
		Meter radius;
	};
}