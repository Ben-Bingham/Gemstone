#include "Apatite/Application.h"

#include "Emerald/Engine.h"

// using namespace Celestite;

// class HelloWorldSystem : public Esperite::System {
// public:
// 	void Step(Esperite::Scene* scene) override {
// 		LOG(std::to_string(glfwGetTime()));
// 	}
// };

using namespace Apatite;
using namespace Emerald;

int main() {
	const Engine engine{};

	const Application app{};
	app.Start();

	// app.window;
	// app.engine;
	//
	//
	//
	// if (!glfwInit()) {
	// 	LOG("Glfw failed to init", Lazuli::LogLevel::TERMINAL);
	// }
	//
	// // GLFWwindow* window = glfwCreateWindow(200, 100, "Window", nullptr, nullptr);
	// //
	// // if (!window) {
	// // 	LOG("Window failed to be created", Lazuli::LogLevel::TERMINAL);
	// // }
	//
	// while (true) {
	// 	glfwPollEvents();
	// 	HelloWorldSystem sys{};
	// 	sys.Step(nullptr);
	// }
	//
	// // Emerald::ECSManager engine{};
	// //
	// // engine.AddSystem(CreatePtr<HelloWorldSystem>());
	// //
	// // engine.Start();
}