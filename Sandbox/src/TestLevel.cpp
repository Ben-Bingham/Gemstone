#include "TestLevel.h"
#include "Core/Engine.h"
#include "Core/Event System/EventHandler.h"
#include "Entity Component System/ComponentView.h"
#include "Input/KeyboardEvents.h"

#include "Rendering/DebugRenderer.h"

#include "Utility/Transform.h"
#include "Rendering/Components/Material.h"
#include "Rendering/Components/Mesh.h"
#include "Rendering/Systems/FpsCameraSystem.h"

using namespace Gem;

class GameController : public System, EventHandler<KeyboardEvents::KeyDown> {
public:
	void Step(EntityManager& manager, float dt) override {
		// ImGui::ShowDemoWindow();
	}

	void HandleEvent(const KeyboardEvents::KeyDown& event) override {
		if (event.key == Key::ESCAPE) {
			LOG("Stoping Level");
			g_Engine.eventManager.Post(StopLevel{});
		}
	}
};

class DebugRenderingTestSystem : public System {
public:
	void Step(EntityManager& entityManager, float dt) override {
		DebugRenderer& debugRenderer = g_Engine.debugRenderer;

		debugRenderer.DrawLine(Vector3f{ 0.0f, 0.0f, 0.0f }, Vector3f{ std::cos(dt), std::sin(dt), 5.0f }, Colour::RED);
	}
};

void TestLevel::Load() {
	Entity ent1 = m_EntityManager.Create();
	m_EntityManager.Insert<Transform>(ent1);
	m_EntityManager.Insert<Material>(ent1, Image{"assets\\earth.jpg"});
	m_EntityManager.Insert<Mesh>(ent1, Cube{});

	Entity ent2 = m_EntityManager.Create();
	m_EntityManager.Insert<Transform>(ent2);
	m_EntityManager.Insert<Material>(ent2, Image{ "assets\\awesomeface.png" });
	m_EntityManager.Insert<Mesh>(ent2, Cube{});
	m_EntityManager.GetComponent<Transform>(ent2).position.x += 3.0f;

	Entity camera = m_EntityManager.Create();
	m_EntityManager.Insert<Transform>(camera);
	m_EntityManager.Insert<Camera>(camera, Camera::CameraType::PERSPECTIVE);
	m_EntityManager.GetComponent<Transform>(camera).position.z = 5.0f;

	m_Ecs.systems.push_back(CreatePtr<GameController>());
	m_Ecs.systems.push_back(CreatePtr<FpsCameraSystem>());
}

void TestLevel::HandleEvent(const StopLevel& event) {
	Stop();
}