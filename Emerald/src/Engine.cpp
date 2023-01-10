#include "Engine.h"

#include "Window.h"

#include "ECS/ComponentManager.h"
#include "ECS/Components/CameraComponent.h"
#include "ECS/Components/RenderingComponent.h"

namespace Emerald {
	Engine::Engine()
		: m_Window(Wavellite::Window::WindowSize::QUARTER_SCREEN), m_Renderer(m_Window) {

	}

	void Engine::init() {
		
	}

	void Engine::start() {
		const auto cameras = ComponentManager::get().getComponents<CameraComponent>();

		if (cameras.first + 1 != cameras.second) {
			LOG("Too many cameras in scene, supply only one or face undefined behaviour."); // TODO allow to switch between cameras
		}

		m_Renderer.setCamera(&(*cameras.first)->getCamera());

		// Game loop
		while (m_Window.isOpen()) { //TODO maybe should be just true?
			m_Renderer.beginFrame();

			auto renderingComponents = ComponentManager::get().getComponents<RenderingComponent>();

			for (auto it = renderingComponents.first; it != renderingComponents.second; ++it) {
				auto val = (*it)->mesh();
				m_Renderer.render(Celestite::createPtr<Ruby::Renderable>((*it)->mesh()->mesh(), (*it)->material()->material(), Celestite::createPtr<Malachite::Transform>((*it)->transform()->transform())));
			}

			m_Renderer.endFrame();
		}
	}

	void Engine::enlist(const Celestite::Ptr<GameObject>& gameObject) {
		m_GameObjects.push_back(gameObject);
	}
}