#include "Engine.h"

#include "Window.h"

#include "Components/CameraComponent.h"
#include "Components/RenderingComponent.h"

namespace Emerald {
	Engine::Engine()
		// , m_Renderer(m_Window)
	{

	}

	void Engine::init() {
		Celestite::Ptr<Ruby::Renderer> renderer = Celestite::createPtr<Ruby::Renderer>(m_Window);

		m_Systems.push_back(renderer);
	}

	void Engine::start() {
		while (m_Window.isOpen()) {
			m_Window.pollEvents();

			for (Celestite::Ptr<Esperite::System>& system : m_Systems) {
				system->Process(activeScene);
			}

			m_Window.swapBuffers();
		}


		// while (true) {
		// 	// const float startTime = m_Time.getTime();
		//
		// 	for (const Esperite::GameObject gb : activeScene->gameObjects) {
		// 		// Scripts
		// 		if (activeScene->HasComponent<Celestite::Ptr<Script>>(gb)) {
		// 			Celestite::Ptr<Script> script = *activeScene->GetComponent<Celestite::Ptr<Script>>(gb);
		//
		// 			script->update(*this);
		// 		}
		//
		// 		// Rendering
		// 		if (activeScene->HasComponent<Ruby::Camera>(gb)) {
		// 			Ruby::Camera* camera = activeScene->GetComponent<Ruby::Camera>(gb);
		// 			m_Renderer.setCamera(camera);
		//
		// 			m_Window.pollEvents();
		//
		// 			if (!m_Window.isOpen()) {
		// 				return;
		// 			}
		//
		// 			m_Renderer.beginFrame();
		//
		// 			for (const Esperite::GameObject renderable : activeScene->gameObjects) {
		// 				if (activeScene->HasComponent<Malachite::Transform>(renderable)) {
		// 					Malachite::Transform* transform = activeScene->GetComponent<Malachite::Transform>(renderable);
		// 					m_Renderer.render(*mesh, *material, *transform);
		// 				}
		// 			}
		//
		// 			m_Renderer.endFrame();
		// 			m_Window.swapBuffers();
		// 		}
		// 	}
		//
		// 	m_DeltaTime = m_Time.getTime() - startTime;
		// }
	}
}