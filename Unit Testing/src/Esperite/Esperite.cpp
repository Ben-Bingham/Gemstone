#include "Esperite.h"

#include <cassert>

#include "Scene.h"

struct Transform {
	Transform(const float x = 0.0f, const float y = 0.0f) : x(x), y(y) {}

	float x;
	float y;
};

void esperite() {
	// Components:
	{
		Esperite::Scene scene{};

		Esperite::GameObject gb = scene.newGameObject();
		assert(!scene.hasComponent<Transform>(gb)); // GameObjects should start with no components.


		scene.addComponent<Transform>(gb);
		assert(scene.hasComponent<Transform>(gb)); // GameObjects should get components once added.


		auto* transform = scene.getComponent<Transform>(gb);

		transform->x += 3.0f;
		assert(scene.getComponent<Transform>(gb)->x == 3.0f); // Changing data of components also modifies data on the game object.


		scene.removeComponent<Transform>(gb);
		assert(!scene.hasComponent<Transform>(gb)); // GameObjects should no longer have a component once its removed.


		Esperite::GameObject gb2 = scene.newGameObject();
		scene.addComponent<Transform>(gb2);
		assert(scene.hasComponent<Transform>(gb2)); // GameObjects should get components once added.

		Esperite::GameObject gb3 = scene.newGameObject();
		scene.addComponent<Transform>(gb3);
		assert(scene.hasComponent<Transform>(gb3)); // GameObjects should get components once added.

		scene.removeComponent<Transform>(gb3);
		scene.removeComponent<Transform>(gb2);

		assert(!scene.hasComponent<Transform>(gb2));
		assert(!scene.hasComponent<Transform>(gb3)); // Components can be removed out of order


		Esperite::GameObject gb4 = scene.newGameObject();
		scene.addComponent<Transform>(gb4);
		auto* transform2 = scene.getComponent<Transform>(gb4);
		scene.removeComponent<Transform>(gb4);
	}

	// Game objects:
	{
		Esperite::Scene scene{};

		Esperite::GameObject gb = scene.newGameObject();
	}

	int i = 1;
}
