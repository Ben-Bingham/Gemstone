#pragma once
#include "MeshHash.h"
#include "MeshRegister.h"

#include "Rendering/Geometry/Cube.h"
#include "Rendering/Geometry/Shapes.h"

namespace Gem {
	/*
	 * Is a component, should be the class the user interacts with
	 */
	class Mesh {
	public:
		Mesh(const Shape& shape = Cube{ });
		// GetRawMesh(some kind of 3d model); // TODO Model loading

		MeshHash hash;

	private:
		static MeshRegister m_Register;
	};
}