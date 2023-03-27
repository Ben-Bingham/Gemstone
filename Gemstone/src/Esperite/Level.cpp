#include "pch.h"
#include "Level.h"

namespace Gem {
	void Level::Step() {
		m_ECS.Step();
	}

	void Level::Stop() {
		m_Running = false;
	}

	bool Level::IsRunning() const {
		return m_Running;
	}
}