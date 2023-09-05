#pragma once
#include "EntityManager.h"
#include <tuple>

namespace Gem {
	template<typename ...ComponentTypes>
	class BaseComponentView { };
	
	template<typename ...ComponentTypes>
	class ComponentView : BaseComponentView<ComponentTypes...> {
	public:
		ComponentView(EntityManager& manager)
			: m_Manager(manager) { }

		class Iterator {
		public:
			Iterator(Entity entity, EntityManager& manager)
				: m_Entity(entity), m_Manager(manager) { }

			std::tuple<ComponentTypes&...> operator*() {
				return std::make_tuple(std::ref(m_Manager.GetComponent<ComponentTypes>(m_Entity))...);
			}

			Iterator& operator++() {
				do {
					m_Entity++;
				} while ((!m_Manager.HasComponents<ComponentTypes...>(m_Entity) || !m_Manager.IsAlive(m_Entity)) && m_Entity != MAX_ENTITIES);
				return *this;
			}

			friend bool operator==(const Iterator& lhs, const Iterator& rhs) { return lhs.m_Entity == rhs.m_Entity; }
			friend bool operator!=(const Iterator& lhs, const Iterator& rhs) { return !(lhs == rhs); }

		private:
			Entity m_Entity;
			EntityManager& m_Manager;
		};

		[[nodiscard]] Iterator begin() const {
			Entity entity{ 0 };
			while ((!m_Manager.HasComponents<ComponentTypes...>(entity) || !m_Manager.IsAlive(entity)) && entity != MAX_ENTITIES) {
				entity++;
			}

			return Iterator{ entity, m_Manager };
		}

		[[nodiscard]] Iterator end() const { return Iterator{ Entity{ MAX_ENTITIES }, m_Manager }; }

	private:
		EntityManager& m_Manager;
	};

	// Iterates all componentMask of one type
	template<typename ComponentType>
	class ComponentView<ComponentType> : BaseComponentView<ComponentType> {
	public:
		ComponentView(EntityManager& manager)
			: m_Manager(manager), m_Pool(manager.GetPool<ComponentType>()) {}

		class Iterator {
		public:
			Iterator(const Entity entity, EntityManager& manager)
				: m_Entity(entity), m_Manager(manager), m_Pool(m_Manager.GetPool<ComponentType>()) { }
		
			ComponentType& operator*() { return *(ComponentType*)m_Pool->Get(m_Entity); }
			ComponentType* operator->() { return (ComponentType*)m_Pool->Get(m_Entity); }

			Iterator& operator++() {
				do {
					m_Entity++;
				} while ((!m_Manager.HasComponent<ComponentType>(m_Entity) || !m_Manager.IsAlive(m_Entity)) && m_Entity != MAX_ENTITIES);
				return *this;
			}

			friend bool operator==(const Iterator& lhs, const Iterator& rhs) { return lhs.m_Entity == rhs.m_Entity; }
			friend bool operator!=(const Iterator& lhs, const Iterator& rhs) { return !(lhs == rhs); }

		private:
			Entity m_Entity;
			EntityManager& m_Manager;
			Ptr<IComponentPool> m_Pool;
		};
		
		[[nodiscard]] Iterator begin() const {
			Entity entity{ 0 };
			while (!m_Manager.HasComponent<ComponentType>(entity) && entity != MAX_ENTITIES) {
				entity++;
			}

			return Iterator{ entity, m_Manager };
		}

		[[nodiscard]] Iterator end() const { return Iterator{ Entity{ MAX_ENTITIES }, m_Manager }; }

	private:
		EntityManager& m_Manager;
		Ptr<IComponentPool> m_Pool;
	};

	// Iterates all entities
	template<>
	class ComponentView<> : BaseComponentView<> {
	public:
		ComponentView(EntityManager& manager)
			: m_Manager(manager) {
			
		}

		class Iterator {
		public:
			Iterator(const Entity entity, EntityManager& manager)
				: m_Entity(entity), m_Manager(manager) {
			}

			Entity& operator*() { return m_Entity; }

			Iterator& operator++() {
				do {
					m_Entity++;
				} while (!m_Manager.IsAlive(m_Entity) && m_Entity != MAX_ENTITIES);
				return *this;
			}

			friend bool operator==(const Iterator& lhs, const Iterator& rhs) { return lhs.m_Entity == rhs.m_Entity; }
			friend bool operator!=(const Iterator& lhs, const Iterator& rhs) { return !(lhs == rhs); }

		private:
			Entity m_Entity;
			EntityManager& m_Manager;
		};

		[[nodiscard]] Iterator begin() const {
			Entity entity{ 0 };
			while (!m_Manager.IsAlive(entity) && entity != MAX_ENTITIES) {
				entity++;
			}

			return Iterator{ entity, m_Manager };
		}

		[[nodiscard]] Iterator end() const { return Iterator{ Entity{ MAX_ENTITIES }, m_Manager }; }

	private:
		EntityManager& m_Manager;
	};
}