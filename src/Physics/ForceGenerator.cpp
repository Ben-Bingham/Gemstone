#include "pch.h"
#include "Physics/ForceGenerator.h"

namespace Gem {
	const float GravitationalConstant{ 6.67430f * std::pow(10.0f, -11.0f) };

	namespace ForceGenerator {
		glm::vec3 gravitationalForce(PhysicsObject* supplier, PhysicsObject* reciever) {
			glm::vec3 displacementBetween = supplier->position - reciever->position;
			Meter distanceBetween = displacementBetween.length();
			Newton gravForce = (Newton)(GravitationalConstant * supplier->mass * reciever->mass) / (distanceBetween * distanceBetween);
			
			glm::vec3 direction = glm::normalize(displacementBetween);
			glm::vec3 gravFoce3D = gravForce * direction;
			return gravFoce3D;
		}
	}
}