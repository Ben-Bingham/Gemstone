#include "Entity Component System/EntityComponentSystem.h"

#include "Rendering/RenderingSystem.h"

namespace Gem {
	EntityComponentSystem::EntityComponentSystem(const bool addDefaultSystems)
		: entityManager(this), componentManager(&entityManager), systemManager(this) {

		if (addDefaultSystems) {
			AddDefaultSystems();
		}
	}

	void EntityComponentSystem::AddDefaultSystems() {
		systemManager.AddSystem(RenderingSystem);
	}
}