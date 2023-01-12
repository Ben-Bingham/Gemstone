#pragma once

#include "GameObject.h"
#include "Log.h"
#include "ComponentPool.h"
#include "Pointer.h"

namespace Esperite {
	class Scene {
	public:
		Scene() = default;

		[[nodiscard]] GameObject newGameObject();

		template<typename T>
		inline T* addComponent(const GameObject gb) {
#ifdef ESPERITE_DEBUG
			if (hasComponent<T>(gb)) {
				LOG("Game Object already has component of this type.", Lazuli::LogLevel::WARNING);
				// The component getting returned is only in Debug mode, if you get this error
				// fix it as it will not return the component in Release
				return getComponent<T>(gb);
			}
#endif
			const unsigned int componentId = getId<T>();

			unsigned int poolIndex;

			if ((int)componentId <= m_FurthestPool) {
				// Pool already exists for component type
				poolIndex = componentId;
			}
			else {
				// Pool does not exist for component type
				m_Pools.emplace_back(Celestite::createUPtr<ComponentPool<T>>());
				m_FurthestPool++;
				poolIndex = m_FurthestPool;
			}

			return ((ComponentPool<T>*) & *m_Pools[poolIndex])->addAndGet(gb);
		}

		template<typename T>
		inline T* getComponent(const GameObject gb) {
			const unsigned int componentId = getId<T>();

			if ((int)componentId <= m_FurthestPool) {
				return ((ComponentPool<T>*)(&*m_Pools[componentId]))->getComponent(gb);
			}

#ifdef ESPERITE_DEBUG
			LOG("Game Object does not contain component", Lazuli::LogLevel::WARNING);
#endif

			return nullptr;
		}

		template<typename T>
		[[nodiscard]] inline bool hasComponent(const GameObject gb) const {
			const unsigned componentId = getId<T>();

			if (componentId + 1 > m_Pools.size()) {
				return false;
			}

			return ((ComponentPool<T>*)(&*m_Pools[componentId]))->hasComponent(gb);
		}

	private:
		std::vector<Celestite::UPtr<IComponentPool>> m_Pools{ };
		int m_FurthestPool{ -1 };
		std::vector<GameObject> m_GameObjects{ };
		GameObjectType m_FurthestGameObject{ 0 };
	};
}