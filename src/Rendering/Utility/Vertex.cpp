#include "Rendering/Utility/Vertex.h"

namespace Gem {
	Vertex::Vertex(const glm::vec3 position, const glm::vec3 normal, const glm::vec2 uv)
		: position(position), normal(normal), uv(uv) { }

	std::vector<float> VertexToFloat(const std::vector<Vertex>& vertices) {
		std::vector<float> reorganizedVertexData;

		reorganizedVertexData.resize(vertices.size() * ELEMENTS_IN_VERTEX);

		std::memcpy(reorganizedVertexData.data(), vertices.data(), reorganizedVertexData.size() * sizeof(float));

		return reorganizedVertexData;
	}
}