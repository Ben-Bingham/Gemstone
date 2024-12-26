#pragma once

#include "PhysicsObject.h"

namespace Gem {
	extern const float GravitationalConstant;

	namespace ForceGenerator {
		glm::vec3 gravitationalForce(PhysicsObject* supplier, PhysicsObject* reciever);
	}
}