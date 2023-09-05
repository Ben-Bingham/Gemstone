#pragma once
#include "Rendering/OpenGl Objects/GlBuffer.h"
#include "Rendering/OpenGl Objects/VertexAttributeObject.h"

namespace Gem {
	class InternalMesh {
	public:
		InternalMesh(const std::vector<float>& vertices, const std::vector<unsigned int>& indices);

		VertexAttributeObject vao;
		VertexBuffer vb;
		IndexBuffer ib;
		size_t indexCount;
	};
}