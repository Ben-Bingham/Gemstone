#include "pch.h"
#include "EntityComponentSystem.h"

namespace Gem {
	void EntityComponentSystem::Load() {
		for (const Celestite::Ptr<Esperite::System>& system : m_Systems) {
			system->StartUp(&m_Scene);
		}
	}

	void EntityComponentSystem::Step() {
		for (const Celestite::Ptr<Esperite::System>& system : m_Systems) {
			system->PreStep(&m_Scene);
		}

		for (const Celestite::Ptr<Esperite::System>& system : m_Systems) {
			system->Step(&m_Scene);
		}

		for (const Celestite::Ptr<Esperite::System>& system : m_Systems) {
			system->EndStep(&m_Scene);
		}
	}

	void EntityComponentSystem::Unload() {
		for (const Celestite::Ptr<Esperite::System>& system : m_Systems) {
			system->ShutDown(&m_Scene);
		}
	}
}