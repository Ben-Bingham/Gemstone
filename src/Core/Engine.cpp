#include "Core/Engine.h"

namespace Gem {
	Engine::Engine() {
		eventSystem.StartUp();
		glfwContext.StartUp();
		window.StartUp();
		openglContext.StartUp();
		renderer.StartUp();
	}

	Engine::~Engine() {
		renderer.ShutDown();
		openglContext.ShutDown();
		window.ShutDown();
		glfwContext.ShutDown();
		eventSystem.ShutDown();
	}
}