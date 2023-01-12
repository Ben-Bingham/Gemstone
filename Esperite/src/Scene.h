#pragma once
#include "GameObject.h"
#include "UglyScene.h"

namespace Esperite {
	class Scene {
	public:
		Scene();

		inline void addGameObject(GameObject& gb) {
			gb.id = SceneManager::get().getScene()->newGameObject();
		}

	private:
		UglyScene m_Scene{ };
	};
}