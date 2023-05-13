#include "pch.h"
#include "Mesh.h"

namespace Gem {
	Cube::Cube(const Vector3f& dimensions)
		: m_Dimensions(dimensions) { }

	std::vector<Vertex> Cube::Vertices() const {
		return std::vector {
			Vertex{ Vector3f{ -0.5f, -0.5f,  0.5f },	Vector3f{  0.0f,  0.0f,  1.0f },		Vector2f{ 0.0f,  0.0f } },
			Vertex{ Vector3f{ -0.5f,  0.5f,  0.5f },	Vector3f{  0.0f,  0.0f,  1.0f },		Vector2f{ 0.0f,  1.0f } },
			Vertex{ Vector3f{  0.5f, -0.5f,  0.5f },	Vector3f{  0.0f,  0.0f,  1.0f },		Vector2f{ 1.0f,  0.0f } },
			Vertex{ Vector3f{  0.5f,  0.5f,  0.5f },	Vector3f{  0.0f,  0.0f,  1.0f },		Vector2f{ 1.0f,  1.0f } },

			Vertex{ Vector3f{  0.5f, -0.5f,  0.5f },	Vector3f{  1.0f,  0.0f,  0.0f },		Vector2f{ 0.0f,  0.0f } },
			Vertex{ Vector3f{  0.5f,  0.5f,  0.5f },	Vector3f{  1.0f,  0.0f,  0.0f },		Vector2f{ 0.0f,  1.0f } },
			Vertex{ Vector3f{  0.5f, -0.5f, -0.5f },	Vector3f{  1.0f,  0.0f,  0.0f },		Vector2f{ 1.0f,  0.0f } },
			Vertex{ Vector3f{  0.5f,  0.5f, -0.5f },	Vector3f{  1.0f,  0.0f,  0.0f },		Vector2f{ 1.0f,  1.0f } },

			Vertex{ Vector3f{ -0.5f, -0.5f, -0.5f },	Vector3f{ -1.0f,  0.0f,  0.0f },		Vector2f{ 0.0f,  0.0f } },
			Vertex{ Vector3f{ -0.5f,  0.5f, -0.5f },	Vector3f{ -1.0f,  0.0f,  0.0f },		Vector2f{ 0.0f,  1.0f } },
			Vertex{ Vector3f{ -0.5f, -0.5f,  0.5f },	Vector3f{ -1.0f,  0.0f,  0.0f },		Vector2f{ 1.0f,  0.0f } },
			Vertex{ Vector3f{ -0.5f,  0.5f,  0.5f },	Vector3f{ -1.0f,  0.0f,  0.0f },		Vector2f{ 1.0f,  1.0f } },

			Vertex{ Vector3f{ -0.5f,  0.5f,  0.5f },	Vector3f{  0.0f,  1.0f,  0.0f },		Vector2f{ 0.0f,  0.0f } },
			Vertex{ Vector3f{ -0.5f,  0.5f, -0.5f },	Vector3f{  0.0f,  1.0f,  0.0f },		Vector2f{ 0.0f,  1.0f } },
			Vertex{ Vector3f{  0.5f,  0.5f,  0.5f },	Vector3f{  0.0f,  1.0f,  0.0f },		Vector2f{ 1.0f,  0.0f } },
			Vertex{ Vector3f{  0.5f,  0.5f, -0.5f },	Vector3f{  0.0f,  1.0f,  0.0f },		Vector2f{ 1.0f,  1.0f } },

			Vertex{ Vector3f{  0.5f, -0.5f, -0.5f },	Vector3f{  0.0f,  0.0f, -1.0f },		Vector2f{ 0.0f,  0.0f } },
			Vertex{ Vector3f{  0.5f,  0.5f, -0.5f },	Vector3f{  0.0f,  0.0f, -1.0f },		Vector2f{ 0.0f,  1.0f } },
			Vertex{ Vector3f{ -0.5f, -0.5f, -0.5f },	Vector3f{  0.0f,  0.0f, -1.0f },		Vector2f{ 1.0f,  0.0f } },
			Vertex{ Vector3f{ -0.5f,  0.5f, -0.5f },	Vector3f{  0.0f,  0.0f, -1.0f },		Vector2f{ 1.0f,  1.0f } },

			Vertex{ Vector3f{ -0.5f, -0.5f, -0.5f },	Vector3f{  0.0f, -1.0f,  0.0f },		Vector2f{ 0.0f,  0.0f } },
			Vertex{ Vector3f{ -0.5f, -0.5f,  0.5f },	Vector3f{  0.0f, -1.0f,  0.0f },		Vector2f{ 0.0f,  1.0f } },
			Vertex{ Vector3f{  0.5f, -0.5f, -0.5f },	Vector3f{  0.0f, -1.0f,  0.0f },		Vector2f{ 1.0f,  0.0f } },
			Vertex{ Vector3f{  0.5f, -0.5f,  0.5f },	Vector3f{  0.0f, -1.0f,  0.0f },		Vector2f{ 1.0f,  1.0f } }
		};
	}

	std::vector<Index> Cube::Indices() const {
		return std::vector<Index> {
			 0,   1,   2,
			 1,   3,   2,
			 4,   5,   6,
			 5,   7,   6,
			 8,   9,  10,
			 9,  11,  10,
			12,  13,  14,
			13,  15,  14,
			16,  17,  18,
			17,  19,  18,
			20,  21,  22,
			21,  23,  22
		};
	}

	// Mesh::Mesh(const std::vector<float>& vertices, const std::vector<unsigned>& indices)
	// 	: indexCount(indices.size()) {
	// 	m_Vao.Bind();
	//
	// 	m_Vb.Bind();
	// 	m_Vb.SetAllData(vertices);
	//
	// 	m_Ib.Bind();
	// 	m_Ib.SetAllData(indices);
	//
	// 	m_Vao.SetLayout({
	// 		{OpenGlContext::VECTOR3F, "l_Position"},
	// 		{OpenGlContext::VECTOR3F, "l_Normal"},
	// 		{OpenGlContext::VECTOR2F, "l_Uv"}
	// 	});
	// }
	//
	// Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<Index>& indices)
	// 	: Mesh(ReorganizeVertexData(vertices), indices) { }
	//
	Mesh::Mesh(const Shape& shape) {
		vertices = shape.Vertices();
		indices = shape.Indices();
	}
	//
	// void Mesh::Bind() {
	// 	m_Vao.Bind();
	// }
	//
	// std::vector<float> Mesh::ReorganizeVertexData(const std::vector<Vertex>& vertices) {
	// 	std::vector<float> reorganizedVertexData;
	// 	reorganizedVertexData.resize(vertices.size() * ELEMENTS_IN_VERTEX);
	// 	memcpy(reorganizedVertexData.data(), vertices.data(), reorganizedVertexData.size());
	//
	// 	return reorganizedVertexData;
	// }
}