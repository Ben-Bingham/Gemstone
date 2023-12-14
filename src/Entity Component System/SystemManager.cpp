#include "Entity Component System/SystemManager.h"

namespace Gem {
	void SystemManager::AddSystem(System system) {
		m_Systems.push_back(system);
	}

	void SystemManager::Systems() {
		for (auto system : m_Systems) {
			system();
		}
	}
}