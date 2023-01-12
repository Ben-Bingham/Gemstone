#pragma once
#include <limits>

#include "UglyGameObject.h"
#include "SceneManager.h"

namespace Esperite {
	class GameObject {
	public:
		GameObject() = default;

		template<typename T>
		void addComponent() const {
			SceneManager::get().getScene()->addComponent<T>(id);
		}

		template<typename T>
		T* getComponent() {
			return SceneManager::get().getScene()->getComponent<T>(id);
		}

		UglyGameObject id{ std::numeric_limits<GameObjectType>::max() };
	};
}
