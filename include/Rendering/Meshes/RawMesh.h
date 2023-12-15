#pragma once
#include <vector>
#include "Rendering/Utility/Index.h"
#include "Rendering/Utility/Vertex.h"

namespace Gem {
	// Contains raw vertex and index data for a mesh
	struct RawMesh {
		RawMesh(const std::vector<Vertex>& vertices, const std::vector<Index>& indices);

		std::vector<Vertex> vertices;
		std::vector<Index> indices;
	};
}