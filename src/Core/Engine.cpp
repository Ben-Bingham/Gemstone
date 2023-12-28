#include "Core/Engine.h"

#include "Core/Event System/EventSystem.h"
#include "Core/GLFWContext.h"
#include "Core/Window.h"
#include "Rendering/OpenGlContext.h"
#include "..\..\include\Rendering\Renderer.h"

namespace Gem {
	Engine::Engine() {
		EventSystem::StartUp();
		GLFWContext::StartUp();
		Window::StartUp();
		OpenGlContext::StartUp();
		Renderer::StartUp();
		Settings::StartUp();
	}

	Engine::~Engine() {
		Settings::ShutDown();
		Renderer::ShutDown();
		OpenGlContext::ShutDown();
		Window::ShutDown();
		GLFWContext::ShutDown();
		EventSystem::ShutDown();
	}
}