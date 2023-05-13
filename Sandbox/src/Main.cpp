#include "TestLevel.h"
#include "Core/Game Flow/Application.h"
#include "Entity Component System/ComponentView.h"
#include "Utility/Log.h"

using namespace Gem;

/*
 * Ordered TODO list:
 * TODO Rendering
 * TODO Settings class (maybe split into rendering settings and other settings?)
 * TODO multiple usage of the same level, and other things with switching levels
 * TODO Debug Rendering
 * TODO Physics
 */

struct Vec2 {
	Vec2(int x = 0, int y = 0)
		: x(x), y(y) {
		LOG("Created Vec2");
	}

	~Vec2() {
		LOG("Destroyed Vec2");
	}

	int x;
	int y;
};

struct B {};

int main() {
	EntityComponentSystem ecs;
	EntityManager& manager = ecs.entityManager;

	Entity ent1 = manager.Create();
	manager.Insert<Vec2>(ent1, -6, -5);

	Entity ent2 = manager.Create();
	manager.Insert<Vec2>(ent2, 1, 2);
	manager.Insert<B>(ent2);

	Entity ent3 = manager.Create();
	manager.Insert<Vec2>(ent3, 3, 4);
	manager.Insert<B>(ent3);

	Entity ent4 = manager.Create();

	LOG("iter:");
	for (auto [vec2, B] : ComponentView<Vec2, B>{manager}) {
		vec2.x += 1;
	}

	Vec2& ent2Vec2 = manager.GetComponent<Vec2>(ent2);
	Vec2& ent3Vec2 = manager.GetComponent<Vec2>(ent3);

	constexpr Application app{};

	app.Load(CreatePtr<TestLevel>());
}