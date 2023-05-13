#pragma once
#include <unordered_map>
#include <tuple>

#include "Components/Mesh.h"

#include "Entity Component System/System.h"

namespace Gem {
	using MeshComponents = std::tuple<VertexAttributeObject, VertexBuffer, IndexBuffer>;

	class RenderingSystem : public System {
	public:
		RenderingSystem() = default;

		void Step(EntityManager& entityManager) override;

	private:
		std::vector<MeshId> m_MeshIds;
		std::unordered_map<MeshId, MeshComponents> m_MeshComponents{ };
	};
}