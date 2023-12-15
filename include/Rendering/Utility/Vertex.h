#pragma once
#include <vector>
#include "Math/Vector.h"

namespace Gem {
	constexpr size_t ELEMENTS_IN_VERTEX = 8;
	struct Vertex {
		Vertex(Vector3f position, Vector3f normal, Vector2f uv);

		Vector3f position;
		Vector3f normal;
		Vector2f uv;
	};

	std::vector<float> VertexToFloat(const std::vector<Vertex>& vertices);
}