#include "pch.h"
#include "Level.h"
#include "Rendering/Systems/RenderingSystem.h"
#include "Rendering/User Interface/UiSystem.h"

namespace Gem {
	void Level::Load() {}

	void Level::Step(float dt) {
		m_Ecs.Step(dt);
	}

	void Level::Unload() {}

	void Level::InternalLoad() {
		// Adding default systems:
		m_Ecs.systems.push_back(CreatePtr<RenderingSystem>());
		m_Ecs.systems.push_back(CreatePtr<UiSystem>());

		Load();
		m_Ecs.Load();
		m_Running = true;
	}

	void Level::InternalUnload() {
		m_Running = false;
		m_Ecs.Unload();
		Unload();
	}

	void Level::Stop() {
		m_Running = false;
	}

	bool Level::IsRunning() const {
		return m_Running;
	}
}