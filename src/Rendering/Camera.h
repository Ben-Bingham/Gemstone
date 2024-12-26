#pragma once
#include <glm/glm.hpp>

namespace Gem {
	// Component;
	class Camera {
	public:
		Camera() = default;

		float fov{ 60 };

		glm::vec3 forward{ glm::vec3{ 0.0f, 0.0f, -1.0f } };
	};
}