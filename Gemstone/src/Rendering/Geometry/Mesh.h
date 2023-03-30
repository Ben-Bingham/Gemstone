#pragma once
#include "MeshData.h"

namespace Gem {
	class Mesh { //TODO try to make this an alias or extend the Ptr<MeshData> class, do same for material class
	public:
		Mesh() = default;

		Ptr<MeshData> mesh;
	};
}