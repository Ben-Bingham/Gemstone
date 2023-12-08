#include "pch.h"
#include "EntityComponentSystem.h"

namespace Gem {
	EntityComponentSystem::EntityComponentSystem()
		: entityManager(this), componentManager(&entityManager) {}
}