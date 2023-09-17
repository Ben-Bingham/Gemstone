#pragma once
#include "InternalMesh.h"
#include <vector>
#include "Rendering/Systems/RenderingSystem.h"
#include "Rendering/Geometry/Shapes.h"

namespace Gem {
	class Mesh {
	public:
		Mesh(const Shape& shape);

		Mesh(const std::vector<Vertex>& vertices, const std::vector<Index>& indices);
		Mesh(const std::vector<float>& vertices, const std::vector<unsigned int>& indices);

		friend void RenderingSystem::Step(EntityManager& entityManager, float dt);

	private:
		Ptr<InternalMesh> m_InternalMesh;
		static std::vector<float> ReorganizeVertexData(const std::vector<Vertex>& vertices);
	};
}