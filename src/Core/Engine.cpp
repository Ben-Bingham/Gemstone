#include "pch.h"
#include "Core/Engine.h"

namespace Gem {
	Engine::Engine() {
		//eventManager.StartUp();
		humanInterfaceDeviceContext.StartUp();
		window.StartUp();

		keyboard.StartUp();
		mouse.StartUp();

		openGlContext.StartUp();
		imGuiContext.StartUp();
		renderer.StartUp();
		debugRenderer.StartUp();
	}

	Engine::~Engine() {
		debugRenderer.ShutDown();
		renderer.ShutDown();
		imGuiContext.ShutDown();
		openGlContext.ShutDown();

		mouse.ShutDown();
		keyboard.ShutDown();

		window.ShutDown();
		humanInterfaceDeviceContext.ShutDown();
		//eventManager.ShutDown();
	}
}