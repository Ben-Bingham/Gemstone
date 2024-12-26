#pragma once
#include <glm/glm.hpp>

namespace Gem {
	// Component
	struct PhysicalProperties {
		glm::vec3 velocity{ 0.0f };
		glm::vec3 acceleration{ 0.0f };
		glm::vec3 netForce{ 0.0f };
		float mass{ 1.0f };
	};
}