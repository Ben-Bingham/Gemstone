#include "pch.h"
#include "Engine.h"

namespace Gem {
	Engine::Engine() {
		eventManager.StartUp();
		humanInterfaceDeviceContext.StartUp();
		window.StartUp();

		m_Keyboard.StartUp();
		m_Mouse.StartUp();

		openGlContext.StartUp();
		imGuiContext.StartUp();
		renderer.StartUp();
	}

	Engine::~Engine() {
		renderer.ShutDown();
		imGuiContext.ShutDown();
		openGlContext.ShutDown();

		m_Mouse.ShutDown();
		m_Keyboard.ShutDown();

		window.ShutDown();
		humanInterfaceDeviceContext.ShutDown();
		eventManager.ShutDown();
	}
}