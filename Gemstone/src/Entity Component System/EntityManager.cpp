#include "pch.h"
#include "EntityManager.h"
#include "EntityComponentSystem.h"

namespace Gem {
	EntityManager::EntityManager(EntityComponentSystem* ecs)
		: m_Ecs(ecs) {

		for (size_t i{ 0 }; i < MAX_ENTITIES; i++) {
			m_UnusedEntities.push(i);
		}
	}

	Entity EntityManager::Create() {
		assert(!m_UnusedEntities.empty() && "Max amount of entities reached");

		const Entity entity = m_UnusedEntities.front();

		m_UnusedEntities.pop();

		return entity;
	}

	void EntityManager::Delete(Entity& entity) {
		assert(!m_Ecs->componentManager.HasAnyComponent(entity) && "Cannot delete entity that still has components.");

		m_UnusedEntities.push(entity);

		entity = DeadEntity;
	}
}