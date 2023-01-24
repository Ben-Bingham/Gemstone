#include "Engine.h"

#include "RenderingContext.h"
#include "Window.h"

#include "Components/CameraComponent.h"
#include "Components/RenderingComponent.h"
#include "Input/Keyboard.h"
#include "Input/Mouse.h"

namespace Emerald {
	Engine::Engine() {
		Wavellite::Window::Get().Init();
		Ruby::RenderingContext::Get().Init();

		Wavellite::Keyboard::Get().Init();
		Wavellite::Mouse::Get().Init();
	}

	void Engine::Start() {
		for (Celestite::Ptr<Esperite::System>& system : m_Systems) {
			system->StartUp(activeScene);
		}

		while (Wavellite::Window::Get().isOpen()) {
			Wavellite::Window::Get().pollEvents(); //TODO window events should be inside a system

			for (Celestite::Ptr<Esperite::System>& system : m_Systems) {
				system->Step(activeScene);
			}

			// m_Window.swapBuffers();
		}

		for (Celestite::Ptr<Esperite::System>& system : m_Systems) {
			system->ShutDown(activeScene);
		}
	}

	Engine& Engine::AddDefaultSystems() {
		m_Systems.push_back(Celestite::CreatePtr<Ruby::Renderer>(Wavellite::Window::Get()));
		// TODO more default systems

		return *this;
	}

	Engine& Engine::AddSystem(const Celestite::Ptr<Esperite::System> system) {
		m_Systems.push_back(system);
		return *this;
	}
}