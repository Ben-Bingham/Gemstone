#pragma once
#include "MeshData.h"
#include "MeshHash.h"

namespace Gem {
	// Contains openGl specific information for meshes, and a hash for that mesh
	struct MeshObject {
		MeshObject(const RawMesh& meshData, MeshHash hash) // TODO move to cpp file
			: mesh(meshData), hash(hash) {
			
		}

		MeshData mesh;
		MeshHash hash;
	};
}