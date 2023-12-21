#include "Entity Component System/SystemManager.h"

#include "Utility/Log.h"

namespace Gem {
	SystemManager::SystemManager(Engine& engine, EntityComponentSystem* ecs)
		: m_Engine(engine), m_Ecs(ecs) { }

	void SystemManager::AddSystem(const System& system) {
		m_Systems.push_back(system);
	}

	void SystemManager::Step() const {
#ifdef GEM_DEBUG
		if (m_Ecs == nullptr) {
			LOG("Ecs became nullptr", LogLevel::ERROR);
			return;
		}
#endif

		for (const auto& system : m_Systems) {
			system(m_Engine, *m_Ecs);
		}
	}
}