#include "Scene.h"

namespace Esperite {
	GameObject Scene::newGameObject() {
		gameObjects.push_back(m_FurthestGameObject);
		m_FurthestGameObject++;
		return gameObjects.back();
	}
}
