#include "pch.h"
#include "Level.h"

namespace Gem {
	void Level::Load() {}

	void Level::Step() {
		m_EntityComponentSystem.Step();
	}

	void Level::Unload() {}

	void Level::InternalLoad() {
		// Adding default systems:

		Load();
		m_EntityComponentSystem.Load();
		m_Running = true;
	}

	void Level::InternalUnload() {
		m_Running = false;
		m_EntityComponentSystem.Unload();
		Unload();
	}

	void Level::Stop() {
		m_Running = false;
	}

	bool Level::IsRunning() const {
		return m_Running;
	}
}