#include "TestLevel.h"
#include "imgui.h"
#include "Core/Engine.h"
#include "Core/Event System/EventHandler.h"
#include "Entity Component System/ComponentView.h"
#include "Input/KeyboardEvents.h"
#include "Rendering/User Interface/UISystem.h"

using namespace Gem;

class GameController : public System, EventHandler<KeyboardEvents::KeyDown> {
public:
	void Step(EntityComponentSystem& ecs) override {
		ImGui::ShowDemoWindow();
	}

	void HandleEvent(const KeyboardEvents::KeyDown& event) override {
		if (event.key == KeyboardEvents::Key::ESCAPE) {
			LOG("Stoping Level");
			g_Engine.eventManager.Post(StopLevel{});
		}
	}
};

void TestLevel::Load() {
	const GameObject gb1{ m_EntityComponentSystem };

	m_EntityComponentSystem.systems.push_back(CreatePtr<GameController>());
}

void TestLevel::HandleEvent(const StopLevel& event) {
	Stop();
}