#include "Engine.h"

#include "ECS/GameObjects/CameraGameObject.h"

namespace Emerald {
	Engine::Engine()
		: m_Renderer(find<CameraGameObject>().cameraRef(), m_Window) {

	}

	void Engine::init() {
		
	}

	void Engine::start() {
		
	}

	void Engine::enlist(const Celestite::Ptr<GameObject>& gameObject) {
		m_GameObjects.push_back(gameObject);
	}
}