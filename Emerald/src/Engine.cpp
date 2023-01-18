#include "Engine.h"

#include "Window.h"

#include "Components/Script.h"
//#include "RigidBody.h"
#include "Components/CameraComponent.h"
#include "Components/RenderingComponent.h"

namespace Emerald {
	Engine::Engine()
		: m_Window(Wavellite::Window::WindowSize::HALF_SCREEN), m_Renderer(m_Window) {

	}

	void Engine::init() {
		
	}

	void Engine::start() {
		while (true) {
// 			for (const Esperite::GameObject gb : activeScene->gameObjects) {
// 				// Rendering
// 				if (activeScene->HasComponent<Ruby::Camera>(gb)) {
// 					Ruby::Camera* camera = activeScene->GetComponent<Ruby::Camera>(gb);
// 					m_Renderer.setCamera(camera);
//
// 					m_Renderer.beginFrame();
//
// 					int i = 0;
// 					for (const Esperite::GameObject renderable : activeScene->gameObjects) {
// 						if (activeScene->HasComponent<Ruby::Mesh>(renderable) &&
// 							activeScene->HasComponent<Celestite::Ptr<Ruby::Material>>(renderable) &&
// 							activeScene->HasComponent<Malachite::Transform>(renderable)) {
//
// 							Ruby::Mesh* mesh = activeScene->GetComponent<Ruby::Mesh>(renderable);
// 							const Celestite::Ptr<Ruby::Material>* material = activeScene->GetComponent<Celestite::Ptr<Ruby::Material>>(renderable);
// 							Malachite::Transform* transform = activeScene->GetComponent<Malachite::Transform>(renderable);
//
// 							m_Renderer.render(*mesh, **material, *transform);
// 							i++;
// 						}
// 					}
// 					LOG("Number of render calls: " + std::to_string(i));
//
// 					m_Renderer.endFrame();
// 				}
//
//
// 				// TODO Physics
// 				/*if (activeScene->hasComponent<Malachite::Transform>(gb) &&
// 					activeScene->hasComponent<Pyrite::RigidBody>(gb)) {
//
// 					Malachite::Transform* transform = activeScene->getComponent<Malachite::Transform>(gb);
// 					Pyrite::RigidBody* rb = activeScene->getComponent<Pyrite::RigidBody>(gb);
// 				}*/
//
// 				if (activeScene->HasComponent<Script>(gb)) {
// 					Script* script = activeScene->GetComponent<Script>(gb);
//
// 					script->update();
// 				}
// 			}
//
// 			// const auto cameras = Esperite::ComponentManager::get().getComponents<CameraComponent>();
// 			//
// 			// if (cameras.first + 1 != cameras.second) {
// 			// 	LOG("Too many cameras in scene, supply only one or face undefined behaviour."); // TODO allow to switch between cameras
// 			// }
// 			//
// 			// m_Renderer.setCamera(&(*cameras.first)->getCamera());
// 			//
// 			// // Game loop
// 			// while (m_Window.isOpen()) { //TODO maybe should be just true?
// 			// 	m_Renderer.beginFrame();
// 			//
// 			// 	auto renderingComponents = Esperite::ComponentManager::get().getComponents<RenderingComponent>();
// 			//
// 			// 	for (auto it = renderingComponents.first; it != renderingComponents.second; ++it) {
// 			// 		auto val = *it;
// 			// 		// m_Renderer.render(*it);
// 			// 	}
// 			//
// 			// 	m_Renderer.endFrame();
// 			// }
		}
	}

	/*void Engine::enlist(const Celestite::Ptr<Esperite::GameObject>& gameObject) {
		m_GameObjects.push_back(gameObject);
	}*/
}