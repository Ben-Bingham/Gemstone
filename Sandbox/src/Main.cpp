#include "Settings.h"

#include "Apatite/Application.h"

#include "Emerald/Engine.h"

#include "Esperite/Level.h"
#include "Celestite/Pointer.h"
#include "TestLevel.h"

#include "gb/GameObject.h"

class HelloWorldSystem : public Esperite::System {
public:
	void Step(Esperite::ECSScene* scene) override {
		LOG(std::to_string(glfwGetTime()));
	}
};

using namespace Gem;
using namespace Celestite;
using namespace Esperite;

struct Vec2 {
	int x;
	int y;
};

int main() {
	Engine engine{};

	Application app{ engine };

	Ptr<TestLevel> scene = CreatePtr<TestLevel>();

	HelloWorldSystem hwSystem{};

	GameObject gb{};

	gb.AddComponent<Vec2>();
	Vec2* pos = gb.GetComponent<Vec2>();

	pos->x++;

	int a = gb.GetComponent<Vec2>()->x;

	app.Load(scene);
}