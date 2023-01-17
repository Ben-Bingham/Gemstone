#pragma once

#include "GameObject.h"
#include "Log.h"
#include "ComponentPool.h"
#include "Pointer.h"

namespace Esperite {
	class Scene {
	private:
		using ComponentPool = BitSetComponentPool;
	public:
		Scene() = default;

		~Scene() {
			for (auto* pool : m_Pools) {
				if (pool != nullptr) {
					delete pool;
				}
			}
		}

		[[nodiscard]] GameObject newGameObject();

		template<typename T>
		void AddComponent(const GameObject gb) {
#ifdef ESPERITE_DEBUG
			// if (hasComponent<T>(gb)) {
			// 	LOG("Game Object already has component of this type.", Lazuli::LogLevel::WARNING);
			// 	// The component getting returned is only in Debug mode, if you get this error
			// 	// fix it as it will not return the component in Release
			// 	return getComponent<T>(gb);
			// }
#endif
			// const unsigned int componentId = getId<T>();

			// unsigned int poolIndex;
			//
			// if ((int)componentId <= m_FurthestPool) {
			// 	// Pool already exists for component type
			// 	poolIndex = componentId;
			// }
			// else {
			// 	// Pool does not exist for component type
			// 	m_Pools.push_back(std::move(Celestite::createUPtr<ComponentPool<T>>()));
			// 	m_FurthestPool++;
			// 	poolIndex = m_FurthestPool;
			// }

			void* component = GetAndOrAddPool<T>()->GetComponent(gb);

			new (component) T();
			//T* pComponent = new (componentPools[componentId]->get(id)) T();
			//new (GetAndOrAddPool<T>()->GetComponent(gb)) T();

			// return ((ComponentPool<T>*)&*m_Pools[poolIndex])->addAndGet(gb);
		}

// 		// If you plan on using this you will need to refresh all the pointers you have to components.
// 		template<typename T>
// 		void RemoveComponent(const GameObject gb) {
// #ifdef ESPERITE_DEBUG
// 			if (!hasComponent<T>(gb)) {
// 				LOG("Game Object aready does not have component of this type.", Lazuli::LogLevel::WARNING);
// 				// TThis error will only be shown in debug mode, be sure to fix it.
// 				return;
// 			}
// #endif
// 			const unsigned int componentId = getId<T>();
//
// 			((ComponentPool<T>*)&*m_Pools[componentId])->removeComponent(gb);
// 		}

		template<typename T>
		[[nodiscard]] T* GetComponent(const GameObject gb) {
#ifdef ESPERITE_DEBUG
			if (!GetAndOrAddPool<T>()->HasComponent(gb)) {
				LOG("Game Object does not have component");
			}
#endif
			return (T*)GetAndOrAddPool<T>()->GetComponent(gb);

// 			const unsigned int componentId = getId<T>();
//
// 			if ((int)componentId <= m_FurthestPool) {
// 				return ((ComponentPool<T>*)(&*m_Pools[componentId]))->getComponent(gb);
// 			}
//
// #ifdef ESPERITE_DEBUG
// 			LOG("Game Object does not contain component", Lazuli::LogLevel::WARNING);
// #endif
//
// 			return nullptr;
		}

		template<typename T>
		[[nodiscard]] bool HasComponent(const GameObject gb) {
			return GetAndOrAddPool<T>()->HasComponent(gb);

			// const unsigned componentId = getId<T>();
			//
			// if (componentId + 1 > m_Pools.size()) {
			// 	return false;
			// }
			//
			// return ((ComponentPool<T>*)(&*m_Pools[componentId]))->hasComponent(gb);
		}

		// void removeGameObject(const GameObject gb) {
		// 	// TODO
		// }

		std::vector<GameObject> gameObjects{ };

	private:
		template<typename T>
		[[nodiscard]] IComponentPool* GetAndOrAddPool() {

			const size_t componentId = getId<T>();

			if (componentId + 1 > m_Pools.size()) {
				m_Pools.resize(componentId + 1, nullptr);
			}

			if (m_Pools[componentId] == nullptr) {
				m_Pools[componentId] = new ComponentPool(sizeof(T), getId<T>());
			}

			return m_Pools[componentId];

			/*if (componentId + 1 <= m_Pools.size()) {
				if (m_Pools[componentId].get() != nullptr) {
					return m_Pools[componentId].get();
				}

				m_Pools[componentId] = Celestite::createUPtr<ComponentPool>(sizeof(T), getId<T>());
			}

			m_Pools.resize(componentId + 1);
			m_Pools[componentId] = Celestite::createUPtr<ComponentPool>(sizeof(T), getId<T>());
			return m_Pools[componentId].get();*/
		}

		std::vector<IComponentPool*> m_Pools{ };
		int m_FurthestPool{ -1 };
		GameObjectType m_FurthestGameObject{ 0 };
	};
}