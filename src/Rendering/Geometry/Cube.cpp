#include "Rendering/Geometry/Cube.h"

namespace Gem {
	Cube::Cube(const glm::vec3& dimensions)
		: m_Dimensions(dimensions) {
	}

	std::vector<Vertex> Cube::Vertices() const {
		return std::vector{
			Vertex{ glm::vec3{ -0.5f, -0.5f,  0.5f },     glm::vec3{  0.0f,  0.0f,  1.0f },		glm::vec2{ 0.0f,  0.0f } },
			Vertex{ glm::vec3{ -0.5f,  0.5f,  0.5f },     glm::vec3{  0.0f,  0.0f,  1.0f },		glm::vec2{ 0.0f,  1.0f } },
			Vertex{ glm::vec3{  0.5f, -0.5f,  0.5f },     glm::vec3{  0.0f,  0.0f,  1.0f },		glm::vec2{ 1.0f,  0.0f } },
			Vertex{ glm::vec3{  0.5f,  0.5f,  0.5f },     glm::vec3{  0.0f,  0.0f,  1.0f },		glm::vec2{ 1.0f,  1.0f } },

			Vertex{ glm::vec3{  0.5f, -0.5f,  0.5f },     glm::vec3{  1.0f,  0.0f,  0.0f },		glm::vec2{ 0.0f,  0.0f } },
			Vertex{ glm::vec3{  0.5f,  0.5f,  0.5f },     glm::vec3{  1.0f,  0.0f,  0.0f },		glm::vec2{ 0.0f,  1.0f } },
			Vertex{ glm::vec3{  0.5f, -0.5f, -0.5f },     glm::vec3{  1.0f,  0.0f,  0.0f },		glm::vec2{ 1.0f,  0.0f } },
			Vertex{ glm::vec3{  0.5f,  0.5f, -0.5f },     glm::vec3{  1.0f,  0.0f,  0.0f },		glm::vec2{ 1.0f,  1.0f } },

			Vertex{ glm::vec3{ -0.5f, -0.5f, -0.5f },     glm::vec3{ -1.0f,  0.0f,  0.0f },		glm::vec2{ 0.0f,  0.0f } },
			Vertex{ glm::vec3{ -0.5f,  0.5f, -0.5f },     glm::vec3{ -1.0f,  0.0f,  0.0f },		glm::vec2{ 0.0f,  1.0f } },
			Vertex{ glm::vec3{ -0.5f, -0.5f,  0.5f },     glm::vec3{ -1.0f,  0.0f,  0.0f },		glm::vec2{ 1.0f,  0.0f } },
			Vertex{ glm::vec3{ -0.5f,  0.5f,  0.5f },     glm::vec3{ -1.0f,  0.0f,  0.0f },		glm::vec2{ 1.0f,  1.0f } },

			Vertex{ glm::vec3{ -0.5f,  0.5f,  0.5f },     glm::vec3{  0.0f,  1.0f,  0.0f },		glm::vec2{ 0.0f,  0.0f } },
			Vertex{ glm::vec3{ -0.5f,  0.5f, -0.5f },     glm::vec3{  0.0f,  1.0f,  0.0f },		glm::vec2{ 0.0f,  1.0f } },
			Vertex{ glm::vec3{  0.5f,  0.5f,  0.5f },     glm::vec3{  0.0f,  1.0f,  0.0f },		glm::vec2{ 1.0f,  0.0f } },
			Vertex{ glm::vec3{  0.5f,  0.5f, -0.5f },     glm::vec3{  0.0f,  1.0f,  0.0f },		glm::vec2{ 1.0f,  1.0f } },

			Vertex{ glm::vec3{  0.5f, -0.5f, -0.5f },     glm::vec3{  0.0f,  0.0f, -1.0f },		glm::vec2{ 0.0f,  0.0f } },
			Vertex{ glm::vec3{  0.5f,  0.5f, -0.5f },     glm::vec3{  0.0f,  0.0f, -1.0f },		glm::vec2{ 0.0f,  1.0f } },
			Vertex{ glm::vec3{ -0.5f, -0.5f, -0.5f },     glm::vec3{  0.0f,  0.0f, -1.0f },		glm::vec2{ 1.0f,  0.0f } },
			Vertex{ glm::vec3{ -0.5f,  0.5f, -0.5f },     glm::vec3{  0.0f,  0.0f, -1.0f },		glm::vec2{ 1.0f,  1.0f } },

			Vertex{ glm::vec3{ -0.5f, -0.5f, -0.5f },     glm::vec3{  0.0f, -1.0f,  0.0f },		glm::vec2{ 0.0f,  0.0f } },
			Vertex{ glm::vec3{ -0.5f, -0.5f,  0.5f },     glm::vec3{  0.0f, -1.0f,  0.0f },		glm::vec2{ 0.0f,  1.0f } },
			Vertex{ glm::vec3{  0.5f, -0.5f, -0.5f },     glm::vec3{  0.0f, -1.0f,  0.0f },		glm::vec2{ 1.0f,  0.0f } },
			Vertex{ glm::vec3{  0.5f, -0.5f,  0.5f },     glm::vec3{  0.0f, -1.0f,  0.0f },		glm::vec2{ 1.0f,  1.0f } }
		};
	}

	std::vector<Index> Cube::Indices() const {
		return std::vector<Index> {
			0, 1, 2,
			1, 3, 2,
			4, 5, 6,
			5, 7, 6,
			8, 9, 10,
			9, 11, 10,
			12, 13, 14,
			13, 15, 14,
			16, 17, 18,
			17, 19, 18,
			20, 21, 22,
			21, 23, 22
		};
	}

	RawMesh Cube::GetRawMesh() const {
		return RawMesh{ Vertices(), Indices() };
	}
}