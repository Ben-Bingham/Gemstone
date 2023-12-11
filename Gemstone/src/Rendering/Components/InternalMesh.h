#pragma once
#include "Rendering/OpenGl Objects/GlBuffer.h"
#include "Rendering/OpenGl Objects/VertexAttributeObject.h"
#include "Gem.h"

namespace Gem {
	class GEM_API InternalMesh {
	public:
		InternalMesh(const std::vector<float>& vertices, const std::vector<unsigned int>& indices);

		VertexAttributeObject vao;
		VertexBuffer vb;
		IndexBuffer ib;
		size_t indexCount;
	};
}