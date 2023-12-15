#pragma once
#include "MeshHash.h"
#include "MeshRegister.h"
#include "Rendering/Geometry/Cube.h"
#include "Rendering/Geometry/Shapes.h"

namespace Gem {
	// Component, Should be used by user
	class Mesh {
	public:
		Mesh(const Shape& shape = Cube{ });
		// GetRawMesh(some kind of 3d model); // TODO Model loading

		MeshHash hash;

		friend bool operator==(const Mesh& lhs, const Mesh& rhs) { return lhs.hash == rhs.hash; }
		friend bool operator!=(const Mesh& lhs, const Mesh& rhs) { return !(lhs == rhs); }

	private:
		static MeshRegister m_Register;
	};
}