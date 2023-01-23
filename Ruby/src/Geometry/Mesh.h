#pragma once
#include "MeshData.h"
#include "Pointer.h"

namespace Ruby {
	class Mesh {
	public:
		Mesh() = default;

		Celestite::Ptr<MeshData> mesh;
	};
}