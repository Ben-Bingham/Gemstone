#pragma once
#include "MeshData.h"
#include "MeshHash.h"

namespace Gem {
	struct MeshObject {
		MeshData data;
		MeshHash hash;
	};
}