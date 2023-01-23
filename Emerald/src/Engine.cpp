#include "Engine.h"

#include "Window.h"

#include "Components/CameraComponent.h"
#include "Components/RenderingComponent.h"

namespace Emerald {
	void Engine::Start() {
		for (Celestite::Ptr<Esperite::System>& system : m_Systems) {
			system->StartUp(activeScene);
		}

		while (m_Window.isOpen()) {
			m_Window.pollEvents(); //TODO window events should be inside a system

			for (Celestite::Ptr<Esperite::System>& system : m_Systems) {
				system->Step(activeScene);
			}

			m_Window.swapBuffers();
		}

		for (Celestite::Ptr<Esperite::System>& system : m_Systems) {
			system->ShutDown(activeScene);
		}
	}

	Engine& Engine::AddDefaultSystems() {
		m_Systems.push_back(Celestite::CreatePtr<Ruby::Renderer>(m_Window));
		// TODO more default systems

		return *this;
	}

	Engine& Engine::AddSystem(const Celestite::Ptr<Esperite::System> system) {
		m_Systems.push_back(system);
		return *this;
	}
}