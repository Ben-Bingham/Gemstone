#include "Rendering/Utility/Vertex.h"

namespace Gem {
	Vertex::Vertex(const Vector3f position, const Vector3f normal, const Vector2f uv)
		: position(position), normal(normal), uv(uv) { }

	std::vector<float> VertexToFloat(const std::vector<Vertex>& vertices) {
		std::vector<float> reorganizedVertexData;

		reorganizedVertexData.resize(vertices.size() * ELEMENTS_IN_VERTEX);

		std::memcpy(reorganizedVertexData.data(), vertices.data(), reorganizedVertexData.size() * sizeof(float));

		return reorganizedVertexData;
	}
}