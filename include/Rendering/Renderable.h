#pragma once
#include "Math/Matrix.h"
#include "Utility/Pointer.h"

namespace Gem {
	class IMaterial;
	class MeshData;

	struct Renderable {
		Ptr<MeshData> mesh;
		Ptr<IMaterial> material;
		Matrix4f modelMatrix;
		// Ptr<IRenderCommand> renderCommand;
	};
}