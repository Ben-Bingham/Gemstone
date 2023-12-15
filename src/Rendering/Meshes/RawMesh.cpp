#include "Rendering/Meshes/RawMesh.h"

namespace Gem {
	RawMesh::RawMesh(const std::vector<Vertex>& vertices, const std::vector<Index>& indices)
		: vertices(vertices), indices(indices) {}
}