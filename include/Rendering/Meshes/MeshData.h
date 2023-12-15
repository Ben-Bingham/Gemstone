#pragma once
#include "RawMesh.h"

#include "Rendering/OpenGl Objects/GlBuffer.h"
#include "Rendering/OpenGl Objects/VertexAttributeObject.h"

namespace Gem {
	class MeshData {
	public:
		MeshData(const RawMesh& rawMesh);

		VertexAttributeObject vao;
		VertexBuffer vb;
		IndexBuffer ib;
		size_t indexCount;
	};
}