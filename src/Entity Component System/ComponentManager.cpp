#include "pch.h"
#include "ComponentManager.h"
#include "EntityManager.h"

namespace Gem {
	ComponentManager::ComponentManager(EntityManager* entityManager)
		: m_EntityManager(entityManager) { }
}