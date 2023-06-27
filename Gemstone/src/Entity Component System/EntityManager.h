#pragma once

#include "ComponentPool.h"
#include <vector>

#include "Utility/Pointer.h"

namespace Gem {
	class EntityManager {
	public:
		EntityManager() = default;

		// Creates an entity.
		Entity Create();
		// Invalidates an entity that doesn't have any components
		void Kill(Entity& entity);

		template<typename ComponentType, typename ...Args>
		void Insert(Entity& entity, Args&&... args) {
			ThrowErrorIfDead(entity);

			if (HasComponent<ComponentType>(entity)) {
				LOG("Entity already has a component of type: " + std::string{ typeid(ComponentType).name() }, LogLevel::ERROR);
				return;
			}

			GetMask(entity) |= ComponentInfo<ComponentType>::mask;

			ComponentType* componentPool = (ComponentType*)GetPool<ComponentType>()->Get(entity);

			// Either make a default constructor for the component or simply pass the correct arguments to the Insert function in order to construct in place.
			new (componentPool) ComponentType{ std::forward<Args>(args)... };
		}

		template<typename ComponentType>
		void Extract(Entity& entity) {
			ThrowErrorIfDead(entity);

			if (!HasComponent<ComponentType>(entity)) {
				LOG("Cannot remove component from entity that dosent have component: " + std::string{ typeid(ComponentType).name() }, LogLevel::ERROR);
				return;
			}

			GetMask(entity) ^= ComponentInfo<ComponentType>::mask;

			ComponentType* componentPool = (ComponentType*)GetPool<ComponentType>()->Get(entity);

			componentPool->~ComponentType();
		}

		template<typename ComponentType>
		ComponentType& GetComponent(Entity entity) {
			ThrowErrorIfDead(entity);

			if (!HasComponent<ComponentType>(entity)) {
				LOG("Cannot get component from entity that dosent have component: " + std::string{ typeid(ComponentType).name() } + " Null refrence will be returned.", LogLevel::ERROR);
			}

			return *(ComponentType*)GetPool<ComponentType>()->Get(entity);
		}

		template<typename ComponentType>
		bool HasComponent(const Entity entity) const {
			if (!IsAlive(entity)) {
				return false;
			}

			const ComponentMask entityMask = GetMask(entity);
			const ComponentMask componentMask = ComponentInfo<ComponentType>::mask;
			
			const ComponentMask result = entityMask & componentMask;
			
			return result == componentMask;
		}

		template<typename ...ComponentTypes>
		bool HasComponents(const Entity entity) const {
			return (HasComponent<ComponentTypes>(entity) && ...);
		}

		template<typename ComponentType>
		Ptr<IComponentPool>& GetPool() const {
			using Info = ComponentInfo<ComponentType>;

			if (Info::id >= m_Pools.size()) {
				m_Pools.resize(Info::id + 1);
			}

			if (m_Pools[Info::id] == nullptr) {
				m_Pools[Info::id] = CreatePtr<ComponentPool<ComponentType>>();
			}

			return m_Pools[Info::id];
		}

		ComponentMask& GetMask(Entity entity) const;
		bool IsAlive(Entity entity) const;

	private:
		void ThrowErrorIfDead(Entity entity) const;

		mutable std::vector<Ptr<IComponentPool>> m_Pools;
		mutable std::vector<std::pair<ComponentMask, bool>> m_EntityDescriptions;
	};
}