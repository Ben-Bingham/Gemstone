#pragma once
#include "ComponentManager.h"
#include "EntityManager.h"

namespace Gem {
	class EntityComponentSystem {
	public:
		EntityComponentSystem();

		EntityManager entityManager;
		ComponentManager componentManager;
		//SystemManager systemManager;
	};
}