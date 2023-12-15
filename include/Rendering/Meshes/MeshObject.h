#pragma once
#include "MeshData.h"
#include "MeshHash.h"

namespace Gem {
	// Contains openGl specific information for meshes, and a hash for that mesh
	struct MeshObject {
		MeshData data;
		MeshHash hash;
	};
}