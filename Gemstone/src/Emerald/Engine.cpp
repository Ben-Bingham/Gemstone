#include "Engine.h"

#include "Wavellite/Timing.h"
#include "Wavellite/Window.h"

#include "Wavellite/Input/Keyboard.h"
#include "Wavellite/Input/Mouse.h"


#include "Systems/Input.h"

#include "Ruby/RenderingContext.h"
#include "Ruby/Systems/ViewMatrixCorrection.h"

namespace Emerald {
	Engine::Engine() {
		Wavellite::Window::Get().Init();
		Ruby::RenderingContext::Get().Init();

		Wavellite::Keyboard::Get().Init();
		Wavellite::Mouse::Get().Init();
	}

	void Engine::Frame() { // TODO work on this
		// m_FrameTime = Wavellite::Time::GetTime();
		//
		// Wavellite::Input::Poll();
		//
		// ExecuteSystems();
		//
		// Ruby::Renderer::Render();
		//
		// float timeDifference{ Wavellite::Time::GetTime() - m_FrameTime };
		// const float requiredTimeDifference = (1.0f / Settings::MaxFPS);
		// while(timeDifference < requiredTimeDifference) {
		// 	timeDifference = Wavellite::Time::GetTime() - m_FrameTime;
		// }
	}

	void Engine::Start() {
		for (const Celestite::Ptr<Esperite::System>& system : m_Systems) {
			system->StartUp(activeScene);
		}

		while (Wavellite::Window::Get().isOpen()) {
			for (const Celestite::Ptr<Esperite::System>& system : m_Systems) {
				system->PreStep(activeScene);
			}

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
		m_Systems.push_back(Celestite::CreatePtr<Input>());
		m_Systems.push_back(Celestite::CreatePtr<Ruby::RenderingSystem>(Wavellite::Window::Get()));
		m_Systems.push_back(Celestite::CreatePtr<Ruby::ViewMatrixCorrection>());
		// TODO more default systems

		return *this;
	}

	Engine& Engine::AddSystem(const Celestite::Ptr<Esperite::System> system) { //TODO maybe should be part of the scene and not engine?
		m_Systems.push_back(system);
		return *this;
	}
}