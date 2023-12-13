#pragma once
#include <queue>
#include <array>
#include "Entity.h"
#include "Component.h"
#include "Gem.h"

namespace Gem {
	class EntityComponentSystem;

	class GEM_API EntityManager {
	public:
		EntityManager(EntityComponentSystem* ecs);

		[[nodiscard]] Entity Create();
		void Delete(Entity& entity);

		std::array<ComponentMask, MAX_ENTITIES> entityMasks{};

	private:
		std::queue<Entity> m_UnusedEntities;
		EntityComponentSystem* m_Ecs;
	};
}