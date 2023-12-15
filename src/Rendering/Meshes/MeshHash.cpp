#include "Rendering/Meshes/MeshHash.h"
#include "Utility/Hashes.h"

namespace Gem {
	MeshHash HashMesh(const std::vector<float>& vertices, const std::vector<unsigned>& indices) {
		MeshHash seed = 289749;
		HashCombine(seed, std::hash<std::vector<float>>{}(vertices), std::hash<std::vector<unsigned int>>{}(indices));

		return seed;
	}
}