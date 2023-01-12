#include "Scene.h"

namespace Esperite {
	GameObject Scene::newGameObject() {
		m_GameObjects.push_back(m_FurthestGameObject);
		m_FurthestGameObject++;
		return m_GameObjects.back();
	}
}
