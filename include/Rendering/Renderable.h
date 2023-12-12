#pragma once
#include "Math/Matrix.h"
#include "Utility/Pointer.h"

namespace Gem {
	class IMaterial;
	class InternalMesh;

	struct Renderable {
		Ptr<InternalMesh> mesh;
		Ptr<IMaterial> material;
		Matrix4f modelMatrix;
		// Ptr<IRenderCommand> renderCommand;
	};
}