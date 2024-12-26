#include "pch.h"
#include "Utility/Transform.h"
#include <glm/glm.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/transform.hpp>

namespace Gem {
	Transform::Transform(const glm::vec3& position, const glm::vec3& scale, const glm::vec3& rotation)
		: position(position), scale(scale), rotation(rotation) {}

	glm::mat4 Transform::Matrix() const {
		glm::mat4 model{ 1.0f };

		model = glm::translate(model, position);
		model = glm::scale(model, scale);
		model = glm::rotate(model, glm::radians(rotation.z), glm::vec3{ 0.0f, 0.0f, 1.0f });
		model = glm::rotate(model, glm::radians(rotation.x), glm::vec3{ 1.0f, 0.0f, 0.0f });
		model = glm::rotate(model, glm::radians(rotation.y), glm::vec3{ 0.0f, 1.0f, 0.0f });

		return model;
	}
}