#include "TestLevel.h"
#include "imgui.h"
#include "Core/Engine.h"
#include "Core/Event System/EventHandler.h"
#include "Entity Component System/ComponentView.h"
#include "Input/KeyboardEvents.h"
#include "Utility/Transform.h"
#include "Rendering/Components/Material.h"
#include "Rendering/Components/Mesh.h"
#include "Rendering/Systems/PerspectiveCameraSystem.h"

using namespace Gem;

class GameController : public System, EventHandler<KeyboardEvents::KeyDown> {
public:
	void Step(EntityManager& manager, float dt) override {
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
	m_EntityManager.Insert<Material>(ent1, Image{"assets\\earth.jpg"});
	m_EntityManager.Insert<Mesh>(ent1, Cube{});

	Entity ent2 = m_EntityManager.Create();
	m_EntityManager.Insert<Transform>(ent2);
	m_EntityManager.Insert<Camera>(ent2, Camera::CameraType::PERSPECTIVE);
	m_EntityManager.GetComponent<Transform>(ent2).position.z = 5.0f;

	m_Ecs.systems.push_back(CreatePtr<GameController>());
	m_Ecs.systems.push_back(CreatePtr<PerspectiveCameraSystem>());
}

void TestLevel::HandleEvent(const StopLevel& event) {
	Stop();
}