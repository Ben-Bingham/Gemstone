#include "pch.h"
#include "Core/Engine.h"

namespace Gem {
	Engine::Engine() {
		eventSystem.StartUp();
		glfwContext.StartUp();
		window.StartUp();
	}

	Engine::~Engine() {
		window.ShutDown();
		glfwContext.ShutDown();
		eventSystem.ShutDown();
	}
}