#include "Rendering/Meshes/Mesh.h"
#include "Rendering/Meshes/MeshRegister.h"

namespace Gem {
	Mesh::Mesh(const Shape& shape) {
		hash = MeshRegister::Get().AddMesh(shape.GetRawMesh());
	}
}