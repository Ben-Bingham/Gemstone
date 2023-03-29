#pragma once
#include "ComponentPool.h"
#include "GameObject.h"
#include "Lazuli/Log.h"

namespace Gem {
	class Scene {
		using ComponentPool = FixedSizeBitSetComponentPool;

	public:
		Scene() = default;

		~Scene() {
			for (auto* pool : m_Pools) {
				delete pool;
			}
		}

		[[nodiscard]] InternalGameObject NewGameObject() {
			if (m_FurthestGameObject >= MAX_GAME_OBJECTS) {
				LOG("Out of game objects", Lazuli::LogLevel::WARNING);
				return NULL_GAME_OBJECT;
			}

			gameObjects.push_back(m_FurthestGameObject);
			m_FurthestGameObject++;
			return gameObjects.back();
		}

		template <typename... Ts>
		[[nodiscard]] InternalGameObject NewGameObject() {
			const InternalGameObject gb = NewGameObject();

			(AddComponent<Ts>(gb), ...);

			return gb;
		}

		template <typename T>
		void AddComponent(const InternalGameObject gb) {
			IComponentPool* pool = GetAndOrAddPool<T>();

			if (pool->HasComponent(gb)) {
				return;
			}

			pool->AddComponent(gb);

			void* component = pool->GetComponent(gb);

			new(component) T(); // All components MUST have a default constructor.
		}

		template <typename T>
		void AddComponent(const InternalGameObject gb, const T component) {
			AddComponent<T>(gb);
			*GetComponent<T>(gb) = component;
		}

		template <typename T>
		[[nodiscard]] T* GetComponent(const InternalGameObject gb) {
			if (!GetAndOrAddPool<T>()->HasComponent(gb)) {
#ifdef ESPERITE_DEBUG
				LOG("Game Object does not have component");
#endif

				return nullptr;
			}

			return static_cast<T*>(GetAndOrAddPool<T>()->GetComponent(gb));
		}

		template <typename T>
		[[nodiscard]] bool HasComponent(const InternalGameObject gb) {
			return GetAndOrAddPool<T>()->HasComponent(gb);
		}

		// void removeGameObject(const InternalGameObject gb) {
		// 	// TODO
		// }

		friend bool operator==(const Scene& lhs, const Scene& rhs) {
			return lhs.gameObjects == rhs.gameObjects
				&& lhs.m_Pools == rhs.m_Pools
				&& lhs.m_FurthestPool == rhs.m_FurthestPool
				&& lhs.m_FurthestGameObject == rhs.m_FurthestGameObject;
		}

		friend bool operator!=(const Scene& lhs, const Scene& rhs) { return !(lhs == rhs); }

		std::vector<InternalGameObject> gameObjects{};

	private:
		template <typename T>
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

		std::vector<IComponentPool*> m_Pools{};
		int m_FurthestPool{-1};
		GameObjectType m_FurthestGameObject{0};
	};
}