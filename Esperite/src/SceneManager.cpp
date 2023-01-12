#include "SceneManager.h"
#include "UglyScene.h"

namespace Esperite {
	SceneManager& SceneManager::get() {
		static SceneManager sceneManager;
		return sceneManager;
	}

	void SceneManager::setScene(UglyScene& scene) {
		m_Scene = &scene;
	}

	UglyScene* SceneManager::getScene() const {
#ifdef ESPERITE_DEBUG
		if (m_Scene == nullptr) {
			LOG("Scene has not been set", Lazuli::LogLevel::WARNING);
		}
#endif
		return m_Scene;
	}
}