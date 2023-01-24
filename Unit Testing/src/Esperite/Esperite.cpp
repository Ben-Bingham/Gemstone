#include "Esperite.h"

#include <cassert>

#include "Scene.h"

struct Transform {
	Transform(const float x = 0.0f, const float y = 0.0f) : x(x), y(y) {}

	float x;
	float y;
};

struct Mesh {
	int val = 0;
};

void esperite() {
	// Components:
	{
		Esperite::Scene scene{};

		Esperite::GameObject gb = scene.NewGameObject();
		assert(!scene.HasComponent<Transform>(gb)); // GameObjects should start with no components.


		scene.AddComponent<Transform>(gb);
		assert(scene.HasComponent<Transform>(gb)); // GameObjects should get components once added.


		auto* transform = scene.GetComponent<Transform>(gb);

		transform->x += 3.0f;
		assert(scene.GetComponent<Transform>(gb)->x == 3.0f); // Changing data of components also modifies data on the game object.


		Esperite::GameObject gb2 = scene.NewGameObject();
		scene.AddComponent<Transform>(gb2);
		assert(scene.HasComponent<Transform>(gb2)); // GameObjects should get components once added.

		Esperite::GameObject gb3 = scene.NewGameObject();
		scene.AddComponent<Transform>(gb3);
		assert(scene.HasComponent<Transform>(gb3)); // GameObjects should get components once added.


		Esperite::GameObject gb4 = scene.NewGameObject<Transform, Mesh>();
		assert(scene.HasComponent<Transform>(gb4) && scene.HasComponent<Mesh>(gb4)); // Advanced Game Object construction works
	}

	// Game objects:
	{
		// Esperite::Scene scene{};

		// Esperite::GameObject gb = scene.NewGameObject();

		// scene.removeGameObject(gb);
	}

	int i = 1;
}
