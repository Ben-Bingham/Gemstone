#include "pch.h"
#include "EntityManager.h"
#include "EntityComponentSystem.h"

namespace Gem {
	EntityManager::EntityManager(EntityComponentSystem* ecs)
		: m_Ecs(ecs) {
		m_UnusedEntities.reserve(MAX_ENTITIES);

		for (size_t i{ 0 }; i < MAX_ENTITIES; i++) {
			m_UnusedEntities.push_back(i);
		}
	}

	Entity EntityManager::Create() { // TODO make this return lower index first
		assert(!m_UnusedEntities.empty() && "Max amount of entities reached");

		const Entity entity = m_UnusedEntities.back();

		m_UnusedEntities.pop_back();

		return entity;
	}

	void EntityManager::Delete(Entity& entity) {
		assert(!m_Ecs->componentManager.HasAnyComponent(entity) && "Cannot delete entity that still has components."); // TODO consider removing the HasAnyComponent function and just check if the mask is empty here

		m_UnusedEntities.push_back(entity);

		entity = DeadEntity;
	}
}