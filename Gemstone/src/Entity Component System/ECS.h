#pragma once
#include "System.h"
#include "Entity Component System/EntityManager.h"
#include "Utility/Pointer.h"

namespace Gem {
	class EntityComponentSystem {
	public:
		void Load();
		void Step(float dt);
		void Unload();

		std::vector<Ptr<System>> systems;
		EntityManager entityManager;
	};
}