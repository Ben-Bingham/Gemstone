#include "pch.h"
#include "ECS.h"

namespace Gem {
	void EntityComponentSystem::Load() const {
		for (const Ptr<System>& system : systems) {
			system->StartUp();
		}
	}

	void EntityComponentSystem::Step(float dt) {
		for (const Ptr<System>& system : systems) {
			system->PreStep(entityManager);
		}

		for (const Ptr<System>& system : systems) {
			system->Step(entityManager, dt);
		}

		for (const Ptr<System>& system : systems) {
			system->EndStep(entityManager);
		}
	}

	void EntityComponentSystem::Unload() const {
		for (const Ptr<System>& system : systems) {
			system->ShutDown();
		}
	}
}