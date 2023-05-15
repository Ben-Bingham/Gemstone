#include "pch.h"
#include "Engine.h"

namespace Gem {
	Engine::Engine() {
		eventManager.StartUp();
		humanInterfaceDeviceContext.StartUp();
		window.StartUp();

		keyboard.StartUp();
		mouse.StartUp();

		openGlContext.StartUp();
		imGuiContext.StartUp();
		renderer.StartUp();
	}

	Engine::~Engine() {
		renderer.ShutDown();
		imGuiContext.ShutDown();
		openGlContext.ShutDown();

		mouse.ShutDown();
		keyboard.ShutDown();

		window.ShutDown();
		humanInterfaceDeviceContext.ShutDown();
		eventManager.ShutDown();
	}
}