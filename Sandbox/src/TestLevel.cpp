#include "TestLevel.h"

#include "Entity Component System/ComponentView.h"

using namespace Gem;

struct Vec2 {
	int x;
	int y;
};

struct StandardInfo {
	std::string name;
	unsigned int age;
};

class HelloWorldSystem : public System {
public:
	void Step(EntityComponentSystem& ecs) override {
		LOG("Hello World");
	}
};

class MovementSystem : public System {
public:
	void Step(EntityComponentSystem& ecs) override {
		for (auto gb : ComponentView<Vec2>{ ecs }) {
			gb.GetComponent<Vec2>()->x += 1;
			LOG(gb.GetComponent<Vec2>()->x);
		}
	}
};

class GameController : public System {
public:
	void Step(EntityComponentSystem& ecs) override {
		// if (m_Level) {
		// 	level.Stop();
		// }
	}
};

TestLevel::TestLevel(Application& app)
	: Level(app) {
	
}

void TestLevel::Load() {
	const GameObject gb1{ m_EntityComponentSystem };
	const GameObject gb2 = GameObject::CreateGameObject<Vec2, StandardInfo>(m_EntityComponentSystem);
	const GameObject gb4 = GameObject::CreateGameObject<Vec2, StandardInfo>(m_EntityComponentSystem, Vec2{ 0, 3 }, StandardInfo{"Bob", 3354345});
	const GameObject gb5 = GameObject(m_EntityComponentSystem).AddComponent(Vec2{ 4, 1 }).AddComponent(StandardInfo{ "tim", 214829034 });

	m_EntityComponentSystem.systems.push_back(CreatePtr<HelloWorldSystem>());
	m_EntityComponentSystem.systems.push_back(CreatePtr<MovementSystem>());
	m_EntityComponentSystem.systems.push_back(CreatePtr<GameController>());
}
