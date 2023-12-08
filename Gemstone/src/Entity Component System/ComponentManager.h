#pragma once
#include <array>

#include "ComponentPool.h"
#include "EntityManager.h"

#include "Utility/Pointer.h"

namespace Gem {
	class EntityManager;

	class ComponentManager {
	public:
		ComponentManager(EntityManager* entityManager);

		template<typename ComponentType, typename...Args>
		ComponentManager& AddComponent(Entity& entity, Args&&... args) {
			assert(!HasComponent<ComponentType>(entity) && "Entity cannot have duplicates of the same component.");

			ComponentType* componentAddress = (ComponentType*)GetPool<ComponentType>()->Get(entity);

			// Either make a default constructor for the component or pass the correct arguments to the AddComponent function.
			new (componentAddress) ComponentType{ std::forward<Args>(args)... };

			m_EntityManager->entityMasks[entity] |= ComponentInfo<ComponentType>::mask;

			return *this;
		}

		template<typename ComponentType>
		ComponentManager& RemoveComponent(Entity& entity) {
			assert(HasComponent<ComponentType>(entity) && "Cannot remove component from entity that does not have component.");

			ComponentType* componentAddress = (ComponentType*)GetPool<ComponentType>()->Get(entity);

			componentAddress->~ComponentType();

			m_EntityManager->entityMasks[entity] ^= ComponentInfo<ComponentType>::mask;

			return *this;
		}

		template<typename ComponentType>
		bool HasComponent(Entity entity) {
			auto mask = ComponentInfo<ComponentType>::mask;

			return mask == (mask & m_EntityManager->entityMasks[entity]);
		}

		template<typename ...ComponentTypes>
		bool HasComponents(Entity entity) {
			ComponentMask mask{};
			mask = (mask |= ... |= ComponentInfo<ComponentTypes>::mask);

			return mask == (mask & m_EntityManager->entityMasks[entity]);
		}

		bool HasAnyComponent(const Entity entity) {
			return !m_EntityManager->entityMasks[entity].none();
		}

		template<typename ComponentType>
		ComponentType& GetComponent(Entity entity) {
			assert(HasComponent<ComponentType>(entity) && "Cannot get component from entity that does not have component.");

			return *(ComponentType*)GetPool<ComponentType>()->Get(entity);
		}

	private:
		template<typename ComponentType>
		[[nodiscard]] Ptr<IComponentPool>& GetPool() {
			const size_t index = ComponentInfo<ComponentType>::id;
			auto pool = m_Pools[index];

			if (!pool) {
				m_Pools[index] = CreatePtr<ComponentPool<ComponentType>>();
			}

			return m_Pools[index];
		}

		std::array<Ptr<IComponentPool>, MAX_COMPONENT_TYPES> m_Pools;
		EntityManager* m_EntityManager;
	};
}