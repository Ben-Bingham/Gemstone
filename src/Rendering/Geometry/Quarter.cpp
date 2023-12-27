#include <vector>
#include "Rendering/Geometry/Quarter.h"

namespace Gem {
	RawMesh Quarter::GetRawMesh() const {
		return RawMesh{ Vertices(), Indices() };
	}

	std::vector<Vertex> Quarter::Vertices() const {
		return std::vector{
			Vertex{ Vector3f{ -1.0f, -1.0f,  0.0f },     Vector3f{  0.0f,  0.0f,  1.0f },		Vector2f{ 0.0f,  0.0f } },
			Vertex{ Vector3f{ -1.0f, 0.0f,  0.0f },     Vector3f{  0.0f,  0.0f,  1.0f },		Vector2f{ 0.0f,  1.0f } },
			Vertex{ Vector3f{ 0.0f, 0.0f,  0.0f },     Vector3f{  0.0f,  0.0f,  1.0f },		Vector2f{ 1.0f,  1.0f } },
			Vertex{ Vector3f{ 0.0f, -1.0f,  0.0f },     Vector3f{  0.0f,  0.0f,  1.0f },		Vector2f{ 1.0f,  0.0f } },
		};
	}

	std::vector<Index> Quarter::Indices() const {
		return std::vector<Index>{
			0, 1, 2,
			0, 2, 3
		};
	}
}