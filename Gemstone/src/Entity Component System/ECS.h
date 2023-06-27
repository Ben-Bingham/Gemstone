#pragma once
#include "System.h"
#include "Entity Component System/EntityManager.h"
#include "Utility/Pointer.h"

namespace Gem {
	class EntityComponentSystem {
	public:
		void Load() const;
		void Step(float dt);
		void Unload() const;

		std::vector<Ptr<System>> systems;
		EntityManager entityManager;
	};
}