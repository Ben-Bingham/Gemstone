#pragma once
#include <limits>

#include "UglyGameObject.h"
#include "SceneManager.h"

namespace Esperite {
	class GameObject {
	public:
		inline GameObject() = default;

		template<typename T>
		inline void addComponent() const {
			SceneManager::get().getScene()->addComponent<T>(id);
		}

		template<typename T>
		inline T* getComponent() {
			return SceneManager::get().getScene()->getComponent<T>(id);
		}

		UglyGameObject id{ std::numeric_limits<GameObjectType>::max() };
	};
}
