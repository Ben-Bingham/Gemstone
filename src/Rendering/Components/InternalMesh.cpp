#include "pch.h"
#include "InternalMesh.h"

namespace Gem {
	InternalMesh::InternalMesh(const std::vector<float>& vertices, const std::vector<unsigned int>& indices)
		: indexCount(indices.size()) {
		vao.Bind();

		vb.Bind();
		vb.SetAllData(vertices);

		ib.Bind();
		ib.SetAllData(indices);

		vao.SetLayout({
			{ OpenGlContext::VECTOR3F, "l_Position" },
			{ OpenGlContext::VECTOR3F, "l_Normal" },
			{ OpenGlContext::VECTOR2F, "l_Uv" }
			});
	}

}