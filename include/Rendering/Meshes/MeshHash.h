#pragma once
#include <vector>

namespace Gem {
	using MeshHash = size_t;

	MeshHash HashMesh(const std::vector<float>& vertices, const std::vector<unsigned int>& indices);
}