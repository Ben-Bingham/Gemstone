#include "Engine.h"

#include "RenderingContext.h"
#include "Window.h"

#include "Input/Keyboard.h"
#include "Input/Mouse.h"


#include "Systems/Input.h"
#include "Systems/ViewMatrixCorrection.h"

namespace Emerald {
	Engine::Engine() {
		Wavellite::Window::Get().Init();
		Ruby::RenderingContext::Get().Init();

		Wavellite::Keyboard::Get().Init();
		Wavellite::Mouse::Get().Init();
	}

	void Engine::Start() {
		for (const Celestite::Ptr<Esperite::System>& system : m_Systems) {
			system->StartUp(activeScene);
		}

		while (Wavellite::Window::Get().isOpen()) {
			for (const Celestite::Ptr<Esperite::System>& system : m_Systems) {
				system->Step(activeScene);
			}

			for (const Celestite::Ptr<Esperite::System>& system : m_Systems) {
				system->EndStep(activeScene);
			}
		}

		for (const Celestite::Ptr<Esperite::System>& system : m_Systems) {
			system->ShutDown(activeScene);
		}
	}

	Engine& Engine::AddDefaultSystems() { //TODO make sure that if this is called multiple times it dosent add them multiple times
		m_Systems.push_back(Celestite::CreatePtr<Ruby::Renderer>(Wavellite::Window::Get()));
		m_Systems.push_back(Celestite::CreatePtr<Input>());
		m_Systems.push_back(Celestite::CreatePtr<Ruby::ViewMatrixCorrection>());
		// TODO more default systems

		return *this;
	}

	Engine& Engine::AddSystem(const Celestite::Ptr<Esperite::System> system) { //TODO maybe should be part of the scene and not engine?
		m_Systems.push_back(system);
		return *this;
	}
}