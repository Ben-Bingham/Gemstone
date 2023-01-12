#include "Scene.h"

#include "UglyScene.h"

namespace Esperite {
	Scene::Scene() {
		SceneManager::get().setScene(m_Scene);
	}

	void Scene::addGameObject(GameObject& gb) {
		gb.id = SceneManager::get().getScene()->newGameObject();
	}
}