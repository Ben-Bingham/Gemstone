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

		friend bool operator==(const Renderable& lhs, const Renderable& rhs) {
			return lhs.mesh == rhs.mesh
				&& lhs.material == rhs.material
				&& lhs.modelMatrix == rhs.modelMatrix;
		}

		friend bool operator!=(const Renderable& lhs, const Renderable& rhs) { return !(lhs == rhs); }
	};
}