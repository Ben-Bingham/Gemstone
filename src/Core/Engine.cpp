#include "Core/Engine.h"

#include "Core/Event System/EventSystem.h"
#include "Core/GLFWContext.h"
#include "Core/Settings.h"
#include "Core/Window.h"
#include "Rendering/OpenGlContext.h"
#include "Input/Keyboard.h"
#include "Input/Mouse.h"
#include "Rendering/Renderer.h"

namespace Gem {
	Engine::Engine() {
		EventSystem::StartUp();
		GLFWContext::StartUp();
		Window::StartUp();
		OpenGlContext::StartUp();
		Renderer::StartUp();
		MeshRegister::StartUp();
		Keyboard::StartUp();
		Mouse::StartUp();
		Settings::StartUp();
	}

	Engine::~Engine() {
		Settings::ShutDown();
		Mouse::ShutDown();
		Keyboard::ShutDown();
		MeshRegister::ShutDown();
		Renderer::ShutDown();
		OpenGlContext::ShutDown();
		Window::ShutDown();
		GLFWContext::ShutDown();
		EventSystem::ShutDown();
	}
}