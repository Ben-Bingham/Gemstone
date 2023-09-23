#include "pch.h"
#include "Engine_New.h"

namespace Gem {
	Engine_New::Engine_New() {
		eventSystem.StartUp();
		glfwContext.StartUp();
	}

	Engine_New::~Engine_New() {
		glfwContext.ShutDown();
		eventSystem.ShutDown();
	}
}