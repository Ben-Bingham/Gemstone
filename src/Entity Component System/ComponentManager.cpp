#include "pch.h"
#include "Entity Component System/ComponentManager.h"
#include "Entity Component System/EntityManager.h"

namespace Gem {
	ComponentManager::ComponentManager(EntityManager* entityManager)
		: m_EntityManager(entityManager) { }
}