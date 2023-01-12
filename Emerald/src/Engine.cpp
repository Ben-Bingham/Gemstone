#include "Engine.h"

#include "Window.h"

// #include "ComponentManager.h"
#include "Components/CameraComponent.h"
#include "Components/RenderingComponent.h"

namespace Emerald {
	Engine::Engine()
		: m_Window(Wavellite::Window::WindowSize::HALF_SCREEN), m_Renderer(m_Window) {

	}

	void Engine::init() {
		
	}

	void Engine::start() {
		// const auto cameras = Esperite::ComponentManager::get().getComponents<CameraComponent>();
		//
		// if (cameras.first + 1 != cameras.second) {
		// 	LOG("Too many cameras in scene, supply only one or face undefined behaviour."); // TODO allow to switch between cameras
		// }
		//
		// m_Renderer.setCamera(&(*cameras.first)->getCamera());
		//
		// // Game loop
		// while (m_Window.isOpen()) { //TODO maybe should be just true?
		// 	m_Renderer.beginFrame();
		//
		// 	auto renderingComponents = Esperite::ComponentManager::get().getComponents<RenderingComponent>();
		//
		// 	for (auto it = renderingComponents.first; it != renderingComponents.second; ++it) {
		// 		auto val = *it;
		// 		// m_Renderer.render(*it);
		// 	}
		//
		// 	m_Renderer.endFrame();
		// }
	}

	void Engine::enlist(const Celestite::Ptr<Esperite::UglyGameObject>& gameObject) {
		m_GameObjects.push_back(gameObject);
	}
}