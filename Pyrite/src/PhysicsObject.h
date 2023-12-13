#pragma once

#include <vector>
#include "Units.h"

#include "Collision/Colliders/Collider.h"

namespace Pyrite {
	using namespace Literals;

	class PhysicsObject {
	public:
		PhysicsObject(/*Kilogram mass, */Point3D position = Point3D{ 0.0_m }/*, Velocity velocity = Velocity{ 0.0_mPerS }, Newton3D netForce = Newton3D{ 0.0_N }*/);
		
		//void addForce(Newton3D force);

		//void calcVelocity(Second deltaTime);
		//void calcPosition(Second deltaTime);

		Kilogram mass;
		//Newton3D netForce;
		//Velocity velocity;
		Point3D position;
	private:
		Collider* collider; //TODO maybe make this a vector
		std::vector<Collider::Collision> collisions;
	};
}