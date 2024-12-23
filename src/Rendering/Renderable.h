#pragma once
#include "Math/Matrix.h"
#include "Utility/Pointer.h"

namespace Gem {
	class BaseMaterial;
	struct MeshObject;

	struct Renderable {
		Ptr<MeshObject> mesh;
		Ptr<BaseMaterial> material;
		Matrix4f modelMatrix;
	};
}