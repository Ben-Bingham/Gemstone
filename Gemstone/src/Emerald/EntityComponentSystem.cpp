#include "pch.h"
#include "EntityComponentSystem.h"

namespace Gem {
	void EntityComponentSystem::Load() {
		for (const Celestite::Ptr<System>& system : systems) {
			system->StartUp(*this);
		}
	}

	void EntityComponentSystem::Step() {
		for (const Celestite::Ptr<System>& system : systems) {
			system->PreStep(*this);
		}

		for (const Celestite::Ptr<System>& system : systems) {
			system->Step(*this);
		}

		for (const Celestite::Ptr<System>& system : systems) {
			system->EndStep(*this);
		}
	}

	void EntityComponentSystem::Unload() {
		for (const Celestite::Ptr<System>& system : systems) {
			system->ShutDown(*this);
		}
	}
}