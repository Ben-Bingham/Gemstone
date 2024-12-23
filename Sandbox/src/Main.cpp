#include <iostream>

#include "imgui.h"

#include <Core/Engine.h>
#include <Core/Game.h>
#include <Rendering/Camera.h>
#include <Utility/Transform.h>

using namespace Gem;

class SandboxLevel : public Level {
public:
	SandboxLevel() {
		ent = ecs.entityManager.Create();

		cam = ecs.entityManager.Create();
		ecs.componentManager.AddComponent<Camera>(cam);
		ecs.componentManager.AddComponent<Transform>(cam);

		ecs.componentManager.GetComponent<Transform>(cam).position.z = 25;
		ecs.componentManager.GetComponent<Transform>(cam).rotation.y = -90.0f;
	}

	~SandboxLevel() {
		ecs.componentManager.RemoveComponent<Transform>(cam);
		ecs.componentManager.RemoveComponent<Camera>(cam);
		ecs.entityManager.Delete(cam);

		ecs.entityManager.Delete(ent);
	}

	Entity ent;
	Entity cam;
};

int main() {
	Engine engine{ };

	Game game{ };

	auto lvl = std::make_shared<SandboxLevel>();

	game.Run(lvl);
}