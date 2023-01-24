#pragma once

#include "GameObject.h"
#include "Log.h"
#include "ComponentPool.h"

namespace Esperite {
	class Scene {
	private:
		using ComponentPool = FixedSizeBitSetComponentPool;
	public:
		Scene() = default;

		~Scene() {
			for (auto* pool : m_Pools) {
				delete pool;
			}
		}

		[[nodiscard]] GameObject NewGameObject() {
			if (m_FurthestGameObject >= MAX_GAME_OBJECTS) {
				LOG("Out of game objects", Lazuli::LogLevel::WARNING);
				return NULL_GAME_OBJECT;
			}

			gameObjects.push_back(m_FurthestGameObject);
			m_FurthestGameObject++;
			return gameObjects.back();
		}

		template<typename ...Ts>
		[[nodiscard]] GameObject NewGameObject() {
			const GameObject gb = NewGameObject();

			(AddComponent<Ts>(gb), ...);

			return gb;
		}

		template<typename T>
		void AddComponent(const GameObject gb) {
			IComponentPool* pool = GetAndOrAddPool<T>();

			if (pool->HasComponent(gb)) {
				return;
			}

			pool->AddComponent(gb);

			void* component = pool->GetComponent(gb);

			new (component) T();
		}

		template<typename T>
		[[nodiscard]] T* GetComponent(const GameObject gb) {
			if (!GetAndOrAddPool<T>()->HasComponent(gb)) {
#ifdef ESPERITE_DEBUG
				LOG("Game Object does not have component");
#endif

				return nullptr;
			}

			return (T*)GetAndOrAddPool<T>()->GetComponent(gb);
		}

		template<typename T>
		[[nodiscard]] bool HasComponent(const GameObject gb) {
			return GetAndOrAddPool<T>()->HasComponent(gb);
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
				m_Pools[componentId] = new ComponentPool(sizeof(T), componentId);
			}

			return m_Pools[componentId];
		}

		std::vector<IComponentPool*> m_Pools{ };
		int m_FurthestPool{ -1 };
		GameObjectType m_FurthestGameObject{ 0 };
	};
}