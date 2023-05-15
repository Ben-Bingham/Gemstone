#include "pch.h"
#include "Mesh.h"

#include "Rendering/OpenGlContext.h"

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

	Mesh::Mesh(const Shape& shape)
		: Mesh(shape.Vertices(), shape.Indices()) {
	}

	Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<Index>& indices)
		: Mesh(ReorganizeVertexData(vertices), indices) {
	}

	Mesh::Mesh(const std::vector<float>& vertices, const std::vector<unsigned int>& indices)
		: m_InternalMesh(CreatePtr<InternalMesh>(vertices, indices)) { }

	std::vector<float> Mesh::ReorganizeVertexData(const std::vector<Vertex>& vertices) {
		std::vector<float> reorganizedVertexData;

		reorganizedVertexData.resize(vertices.size() * ELEMENTS_IN_VERTEX);

		std::memcpy(reorganizedVertexData.data(), vertices.data(), reorganizedVertexData.size() * sizeof(float));
	
		return reorganizedVertexData;
	}
}