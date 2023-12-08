#pragma once
#include "ComponentManager.h"
#include "EntityManager.h"

namespace Gem {
	class EntityComponentSystem { // TODO give each ECS an index, and use that to compare them in the View iterators.
	public:
		EntityComponentSystem();

		EntityManager entityManager;
		ComponentManager componentManager;
	};
}