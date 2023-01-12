#include "Scene.h"

#include "UglyScene.h"

namespace Esperite {
	Scene::Scene() {
		SceneManager::get().setScene(m_Scene);
	}
}