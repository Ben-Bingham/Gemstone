#include "Engine.h"

namespace Emerald {
	Engine::Engine() {
		m_GlfwContext.StartUp();
	}

	Engine::~Engine() {
		m_GlfwContext.ShutDown();
	}
}