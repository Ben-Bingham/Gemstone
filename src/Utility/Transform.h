#pragma once

#include "Gem.h"
#include <glm/glm.hpp>

namespace Gem {
	class Transform {
	public:
		Transform(
			const glm::vec3& position = glm::vec3{ 0.0f },
			const glm::vec3& scale = glm::vec3{ 1.0f },
			const glm::vec3& rotation = glm::vec3{ 0.0f }
		);

		glm::vec3 position;
		glm::vec3 scale;
		glm::vec3 rotation; // Degrees

		[[nodiscard]] glm::mat4 Matrix() const;
	};
}