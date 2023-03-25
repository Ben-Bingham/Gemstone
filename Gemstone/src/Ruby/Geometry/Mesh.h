#pragma once
#include "MeshData.h"
#include "Celestite/Pointer.h"

namespace Ruby {
	class Mesh { //TODO try to make this an alias or extend the Ptr<MeshData> class, do same for material class
	public:
		Mesh() = default;

		Celestite::Ptr<MeshData> mesh;
	};
}