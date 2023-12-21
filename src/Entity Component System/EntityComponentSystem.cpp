#include "Entity Component System/EntityComponentSystem.h"

#include "Rendering/RenderingSystem_New.h"

namespace Gem {
	EntityComponentSystem::EntityComponentSystem(Engine& engine, const bool addDefaultSystems)
		: entityManager(this), componentManager(&entityManager), systemManager(engine, this) {

		if (addDefaultSystems) {
			AddDefaultSystems();
		}
	}

	void EntityComponentSystem::AddDefaultSystems() {
		systemManager.AddSystem(RenderingSystem_New);
	}
}