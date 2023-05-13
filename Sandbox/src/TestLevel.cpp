#include "TestLevel.h"
#include "imgui.h"
#include "Core/Engine.h"
#include "Core/Event System/EventHandler.h"
#include "Entity Component System/ComponentView.h"
#include "Input/KeyboardEvents.h"
#include "Utility/Transform.h"
#include "New Rendering/Components/Material.h"
#include "New Rendering/Components/Mesh.h"

using namespace Gem;

class GameController : public System, EventHandler<KeyboardEvents::KeyDown> {
public:
	void Step(EntityManager& manager) override {
		// ImGui::ShowDemoWindow();
	}

	void HandleEvent(const KeyboardEvents::KeyDown& event) override {
		if (event.key == KeyboardEvents::Key::ESCAPE) {
			LOG("Stoping Level");
			g_Engine.eventManager.Post(StopLevel{});
		}
	}
};

void TestLevel::Load() {
	Entity ent1 = m_EntityManager.Create();
	m_EntityManager.Insert<Transform>(ent1);
	// const GameObject gb1{ m_Ecs };
	// GameObject block = GameObject::CreateGameObject<Transform, Material, Mesh>( m_Ecs, Transform{}, Material{Image{"assets\\TestTexture.png"}}, Mesh{ Cube{} });

	m_Ecs.systems.push_back(CreatePtr<GameController>());
}

void TestLevel::HandleEvent(const StopLevel& event) {
	Stop();
}