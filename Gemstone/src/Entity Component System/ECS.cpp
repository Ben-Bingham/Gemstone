#include "pch.h"
#include "ECS.h"

namespace Gem {
	void EntityComponentSystem::Load() {
		for (const Ptr<System>& system : systems) {
			system->StartUp(entityManager);
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

	void EntityComponentSystem::Unload() {
		for (const Ptr<System>& system : systems) {
			system->ShutDown(entityManager);
		}
	}
}