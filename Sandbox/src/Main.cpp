#include <iostream>

#include "imgui.h"

#include <Core/Engine.h>
#include <Core/Game.h>
#include <Rendering/Camera.h>
#include <Utility/Transform.h>
#include <Rendering/Meshes/Mesh.h>
#include <Physics/PhysicalProperties.h>
#include <Physics/Visualization/PhysicsVisualizationComponent.h>
#include <Physics/Collisions/Colliders/Collider.h>
#include <Rendering/Materials/Material.h>
#include <Rendering/Materials/MaterialFactory.h>

using namespace Gem;

class SandboxLevel : public Level {
public:
	SandboxLevel() {
		cam = ecs.entityManager.Create();
		ecs.componentManager.AddComponent<Camera>(cam);
		ecs.componentManager.AddComponent<Transform>(cam);

		ecs.componentManager.GetComponent<Transform>(cam).position.z = 25;
		ecs.componentManager.GetComponent<Transform>(cam).rotation.y = -90.0f;

		ball = ecs.entityManager.Create();
		ecs.componentManager.AddComponent<Transform>(ball);
		ecs.componentManager.AddComponent<Mesh>(ball);
		ecs.componentManager.AddComponent<Material>(ball, m_WhiteMaterial);
		ecs.componentManager.AddComponent<PhysicalProperties>(ball);
		ecs.componentManager.AddComponent<PhysicsVisualizationComponent>(ball);
		ecs.componentManager.AddComponent<Collider>(ball);

		ecs.componentManager.GetComponent<Transform>(ball).scale = glm::vec3{ 0.6f, 0.6f, 0.6f };
		ecs.componentManager.GetComponent<PhysicalProperties>(ball).velocity = glm::vec3{ 1.0f, 0.0f, 0.0f } * 5.0f;
	}

	~SandboxLevel() {
		ecs.componentManager.RemoveComponent<Collider>(ball);
		ecs.componentManager.RemoveComponent<PhysicsVisualizationComponent>(ball);
		ecs.componentManager.RemoveComponent<PhysicalProperties>(ball);
		ecs.componentManager.RemoveComponent<Material>(ball);
		ecs.componentManager.RemoveComponent<Mesh>(ball);
		ecs.componentManager.RemoveComponent<Transform>(ball);
		ecs.entityManager.Delete(ball);

		ecs.componentManager.RemoveComponent<Transform>(cam);
		ecs.componentManager.RemoveComponent<Camera>(cam);
		ecs.entityManager.Delete(cam);
	}

	Entity cam;
	Entity ball;

	SolidColour m_WhiteMaterial{ CreateMaterial(Colour::White) };
};

int main() {
	Path::SetGemAssets("../");

	Engine engine{ };

	Game game{ };

	auto lvl = std::make_shared<SandboxLevel>();

	game.Run(lvl);
}