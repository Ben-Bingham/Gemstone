#pragma once

#include <glm/glm.hpp>

#include <vector>
#include "Units.h"

//#include "Collision/Colliders/Collider.h"

namespace Gem {
	using namespace Literals;

	class PhysicsObject {
	public:
		PhysicsObject(/*Kilogram mass, */glm::vec3 position = glm::vec3{ 0.0f }/*, Velocity velocity = Velocity{ 0.0_mPerS }, Newton3D netForce = Newton3D{ 0.0_N }*/);
		
		//void addForce(Newton3D force);

		//void calcVelocity(Second deltaTime);
		//void calcPosition(Second deltaTime);

		Kilogram mass;
		//Newton3D netForce;
		//Velocity velocity;
		glm::vec3 position;
	private:
		//Collider* collider; //TODO maybe make this a vector
		//std::vector<Collider::Collision> collisions;
	};
}