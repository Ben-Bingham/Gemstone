#pragma once
#include <vector>
#include "System.h"

namespace Gem {
	class SystemManager {
	public:
		SystemManager(Engine& engine, EntityComponentSystem* ecs);

		void AddSystem(const System& system);

		void Step() const;

	private:
		std::vector<System> m_Systems;

		EntityComponentSystem* m_Ecs;
		Engine& m_Engine;
	};
}