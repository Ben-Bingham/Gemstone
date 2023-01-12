#pragma once
#include "GameObject.h"
#include "UglyScene.h"

namespace Esperite {
	class Scene {
	public:
		Scene();

		void addGameObject(GameObject& gb);

	private:
		UglyScene m_Scene{ };
	};
}