#include "pch.h"
#include "Level.h"

namespace Gem {
	Level::Level(Application& app)
		: m_App(app) {
		
	}

	void Level::Load() {}

	void Level::Step() {
		m_EntityComponentSystem.Step();
	}

	void Level::Unload() {}

	void Level::InternalLoad() {
		Load();
		m_EntityComponentSystem.Load();
	}

	void Level::InternalUnload() {
		m_EntityComponentSystem.Unload();
		Unload();
	}

	void Level::Stop() {
		m_Running = false;
	}

	bool Level::IsRunning() const {
		return m_Running;
	}

	EntityComponentSystem& Level::ECS() { return m_EntityComponentSystem; }
}