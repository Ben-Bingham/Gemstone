#pragma once
#include <vector>
#include <glm/glm.hpp>

namespace Gem {
	constexpr size_t ELEMENTS_IN_VERTEX = 8;
	struct Vertex {
		Vertex(glm::vec3 position, glm::vec3 normal, glm::vec2 uv);

		glm::vec3 position;
		glm::vec3 normal;
		glm::vec2 uv;
	};

	std::vector<float> VertexToFloat(const std::vector<Vertex>& vertices);
}