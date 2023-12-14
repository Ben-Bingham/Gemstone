#pragma once
#include "EntityComponentSystem.h"
#include "Gem.h"

namespace Gem {
	template<typename ...ComponentTypes>
	class BaseView { };

	// Iterates all entities with specified components
	template<typename ...ComponentTypes>
	class View : public BaseView<ComponentTypes...> {
	public:
		View(EntityComponentSystem& ecs) 
			: m_ECS(ecs) { }

		class Iterator {
		public:
			Iterator(EntityComponentSystem& ecs, Entity entity)
				: m_ECS(ecs), m_Entity(entity) {}

			std::tuple<Entity&, ComponentTypes&...> operator*() {
				return std::forward_as_tuple(m_Entity, m_ECS.componentManager.GetComponent<ComponentTypes>(m_Entity)...);
			}

			Iterator& operator++() {
				for (Entity ent = m_Entity + 1; ent != MAX_ENTITIES; ent++) {
					m_Entity++;
					if (m_ECS.componentManager.HasComponents<ComponentTypes...>(ent)) {
						return *this;
					}
				}

				m_Entity = DeadEntity;
				return *this;
			}

			friend bool operator==(const Iterator& lhs, const Iterator& rhs) { return lhs.m_Entity == rhs.m_Entity; }
			friend bool operator!=(const Iterator& lhs, const Iterator& rhs) { return !(lhs == rhs); }

		private:
			EntityComponentSystem& m_ECS;
			Entity m_Entity{};
		};

		Iterator begin() {
			for (Entity ent = 0; ent != MAX_ENTITIES; ent++) {
				if (m_ECS.componentManager.HasComponents<ComponentTypes...>(ent)) {
					return Iterator{ m_ECS, ent };
				}
			}

			return end();
		}

		Iterator end() {
			return Iterator{ m_ECS, DeadEntity };
		}

	private:
		EntityComponentSystem& m_ECS;
	};

	// Iterates all components of a singal type
	template<typename ComponentType>
	class View<ComponentType> : public BaseView<ComponentType> {
	public:
		View(EntityComponentSystem& ecs)
			: m_ECS(ecs) { }

		class Iterator {
		public:
			Iterator(EntityComponentSystem& ecs, Entity entity) 
				: m_ECS(ecs), m_Entity(entity) {}

			std::tuple<Entity&, ComponentType&> operator*() {
				return std::forward_as_tuple(m_Entity, m_ECS.componentManager.GetComponent<ComponentType>(m_Entity));
			}

			Iterator& operator++() {
				for (Entity ent = m_Entity + 1; ent != MAX_ENTITIES; ent++) {
					m_Entity++;
					if (m_ECS.componentManager.HasComponent<ComponentType>(ent)) {
						return *this;
					}
				}

				m_Entity = DeadEntity;
				return *this;
			}

			friend bool operator==(const Iterator& lhs, const Iterator& rhs) { return lhs.m_Entity == rhs.m_Entity; } 
			friend bool operator!=(const Iterator& lhs, const Iterator& rhs) { return !(lhs == rhs); }

		private:
			EntityComponentSystem& m_ECS;
			Entity m_Entity{};
		};

		Iterator begin() { 
			for (Entity ent = 0; ent != MAX_ENTITIES; ent++) {
				if (m_ECS.componentManager.HasComponent<ComponentType>(ent)) {
					return Iterator{ m_ECS, ent };
				}
			}

			return end();
		}

		Iterator end() { 
			return Iterator{ m_ECS, DeadEntity };
		}

	private:
		EntityComponentSystem& m_ECS;
	};

	// Iterates all entities with at least one component
	template<>
	class View<> : public BaseView<> {
	public:
		View(EntityComponentSystem& ecs)
			: m_ECS(ecs) { }

		class Iterator {
		public:
			Iterator(EntityComponentSystem& ecs, Entity entity)
				: m_ECS(ecs), m_Entity(entity) {}

			Entity operator*() {
				return m_Entity;
			}

			Iterator& operator++() {
				for (Entity ent = m_Entity + 1; ent != MAX_ENTITIES; ent++) {
					m_Entity++;
					if (m_ECS.componentManager.HasAnyComponent(ent)) {
						return *this;
					}
				}

				m_Entity = DeadEntity;
				return *this;
			}

			friend bool operator==(const Iterator& lhs, const Iterator& rhs) { return lhs.m_Entity == rhs.m_Entity; }
			friend bool operator!=(const Iterator& lhs, const Iterator& rhs) { return !(lhs == rhs); }

		private:
			EntityComponentSystem& m_ECS;
			Entity m_Entity{};
		};

		Iterator begin() {
			for (Entity ent = 0; ent != MAX_ENTITIES; ent++) {
				if (m_ECS.componentManager.HasAnyComponent(ent)) {
					return Iterator{ m_ECS, ent };
				}
			}

			return end();
		}

		Iterator end() {
			return Iterator{ m_ECS, DeadEntity };
		}

	private:
		EntityComponentSystem& m_ECS;
	};
}