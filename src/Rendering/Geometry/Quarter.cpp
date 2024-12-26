#include <vector>
#include "Rendering/Geometry/Quarter.h"

namespace Gem {
	RawMesh Quarter::GetRawMesh() const {
		return RawMesh{ Vertices(), Indices() };
	}

	std::vector<Vertex> Quarter::Vertices() const {
		return std::vector{
			Vertex{ glm::vec3{ -1.0f, -1.0f,  0.0f },     glm::vec3{  0.0f,  0.0f,  1.0f },		glm::vec2{ 0.0f,  0.0f } },
			Vertex{ glm::vec3{ -1.0f, 0.0f,  0.0f },     glm::vec3{  0.0f,  0.0f,  1.0f },		glm::vec2{ 0.0f,  1.0f } },
			Vertex{ glm::vec3{ 0.0f, 0.0f,  0.0f },     glm::vec3{  0.0f,  0.0f,  1.0f },		glm::vec2{ 1.0f,  1.0f } },
			Vertex{ glm::vec3{ 0.0f, -1.0f,  0.0f },     glm::vec3{  0.0f,  0.0f,  1.0f },		glm::vec2{ 1.0f,  0.0f } },
		};
	}

	std::vector<Index> Quarter::Indices() const {
		return std::vector<Index>{
			0, 1, 2,
			0, 2, 3
		};
	}
}