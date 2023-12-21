#include "Rendering/Meshes/Mesh.h"

namespace Gem {
	Mesh::Mesh(const Shape& shape) {
		hash = meshRegister.AddMesh(shape.GetRawMesh());
	}

	MeshRegister Mesh::meshRegister{ };
}