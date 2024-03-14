#include "Entity Component System/EntityComponentSystem.h"

#include "Physics/PhysicsSystem_New.h"
#include "Physics/Collisions/CollisionSystem.h"
#include "Physics/Visualization/PhysicsVisualizationSystem.h"

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
		systemManager.AddSystem(CollisionSystem);
		systemManager.AddSystem(PhysicsSystem_New);
		systemManager.AddSystem(PhysicsVisualizationSystem);
	}
}