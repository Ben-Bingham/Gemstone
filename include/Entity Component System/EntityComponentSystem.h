#pragma once
#include "EntityManager.h"
#include "ComponentManager.h"
#include "Entity Component System/SystemManager.h"

namespace Gem {
	class EntityComponentSystem { // TODO give each ECS an index, and use that to compare them in the View iterators.
	public:
		EntityComponentSystem(Engine& engine, bool addDefaultSystems = true);

		void AddDefaultSystems();

		EntityManager entityManager;
		ComponentManager componentManager;
		SystemManager systemManager;
	};
}