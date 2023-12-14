#pragma once
#include <vector>
#include "System.h"

namespace Gem {
	class SystemManager {
	public:
		SystemManager() = default;

		void AddSystem(System system);

		void Systems();

	private:
		std::vector<System> m_Systems;
	};
}