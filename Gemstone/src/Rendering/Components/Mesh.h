#pragma once
#include <vector>

#include "Entity Component System/EntityManager.h"

#include "Rendering/Systems/RenderingSystem.h"
#include "Rendering/Geometry/Shapes.h"
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