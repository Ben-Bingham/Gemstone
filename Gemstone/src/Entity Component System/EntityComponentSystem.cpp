#include "pch.h"
#include "EntityComponentSystem.h"
#include "System.h"

namespace Gem {
	void EntityComponentSystem::Load() {
		for (const Ptr<System>& system : systems) {
			system->StartUp(*this);
		}
	}

	void EntityComponentSystem::Step() {
		for (const Ptr<System>& system : systems) {
			system->PreStep(*this);
		}

		for (const Ptr<System>& system : systems) {
			system->Step(*this);
		}

		for (const Ptr<System>& system : systems) {
			system->EndStep(*this);
		}
	}

	void EntityComponentSystem::Unload() {
		for (const Ptr<System>& system : systems) {
			system->ShutDown(*this);
		}
	}

	bool operator==(const EntityComponentSystem& lhs, const EntityComponentSystem& rhs) {
		return lhs.scene == rhs.scene
			&& lhs.systems == rhs.systems;
	}

	bool operator!=(const EntityComponentSystem& lhs, const EntityComponentSystem& rhs) {
		return !(lhs == rhs);
	}
}