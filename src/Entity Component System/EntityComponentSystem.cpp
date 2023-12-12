#include "pch.h"
#include "Entity Component System/EntityComponentSystem.h"

namespace Gem {
	EntityComponentSystem::EntityComponentSystem()
		: entityManager(this), componentManager(&entityManager) {}
}