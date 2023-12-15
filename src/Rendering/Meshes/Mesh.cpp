#include "Rendering/Meshes/Mesh.h"

namespace Gem {
	Mesh::Mesh(const Shape& shape) {
		hash = m_Register.AddMesh(shape.GetRawMesh());
	}

	MeshRegister Mesh::m_Register{ };
}