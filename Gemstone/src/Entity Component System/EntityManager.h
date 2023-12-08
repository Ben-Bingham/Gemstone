#pragma once
#include <vector>
#include <array>

#include "Component.h"

namespace Gem {
	class EntityComponentSystem;

	using Entity = size_t; // TODO move to seperate file IF POSSIBLE
	static constexpr Entity DeadEntity{ std::numeric_limits<size_t>::max() };

	class EntityManager {
	public:
		EntityManager(EntityComponentSystem* ecs);

		[[nodiscard]] Entity Create();
		void Delete(Entity& entity);

		std::array<ComponentMask, MAX_ENTITIES> entityMasks{};

	private:
		std::vector<Entity> m_UnusedEntities;
		EntityComponentSystem* m_Ecs;
	};
}