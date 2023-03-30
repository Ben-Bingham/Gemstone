#pragma once
#include "EntityComponentSystem.h"
#include "InternalGameObject.h"
#include "GameObject.h"

namespace Gem {
    template<typename... Ts>
	class ComponentView {
	public:
		ComponentView(EntityComponentSystem& ecs)
			: m_EntityComponentSystem(ecs) {
  
		}

        class Iterator {
		public:
            Iterator(EntityComponentSystem& ecs, const InternalGameObject handle = NULL_GAME_OBJECT, const bool all = false)
	            : m_EntityComponentSystem(ecs), m_Handle(handle), m_All(all) {

            }

            Iterator operator++() { //TODO could probably be optimized
                if (m_All) {
                    return Iterator{ m_EntityComponentSystem, m_Handle++, m_All };
                }

                bool found{ false };

                for (auto& gb : m_EntityComponentSystem.scene.gameObjects) {
                    if (gb <= m_Handle) {
                        continue;
                    }

                    if ((m_EntityComponentSystem.scene.HasComponent<Ts>(gb) && ...)) {
                        m_Handle = gb;
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    m_Handle = (GameObjectType)m_EntityComponentSystem.scene.gameObjects.size();
                }

                return Iterator{ m_EntityComponentSystem, m_Handle, m_All };
            }

            GameObject operator*() const {
                return GameObject{ m_EntityComponentSystem, m_Handle };
            }

            friend bool operator==(const Iterator& lhs, const Iterator& rhs) {
	            return lhs.m_EntityComponentSystem == rhs.m_EntityComponentSystem
		            && lhs.m_Handle == rhs.m_Handle;
            }

            friend bool operator!=(const Iterator& lhs, const Iterator& rhs) { return !(lhs == rhs); }

        private:
            EntityComponentSystem& m_EntityComponentSystem;
            InternalGameObject m_Handle;
            bool m_All;
        };

        [[nodiscard]] Iterator begin() const {
            if constexpr (sizeof...(Ts) == 0) {
                return Iterator{ m_EntityComponentSystem, 0, true };
            }

            for (auto& gb : m_EntityComponentSystem.scene.gameObjects) {
                if ((m_EntityComponentSystem.scene.HasComponent<Ts>(gb) && ...)) {
                    return Iterator{ m_EntityComponentSystem, gb, false };
                }
            }
            return Iterator{ m_EntityComponentSystem, (GameObjectType)m_EntityComponentSystem.scene.gameObjects.size(), false };
        }

        [[nodiscard]] Iterator end() const {
            return Iterator{ m_EntityComponentSystem, (GameObjectType)m_EntityComponentSystem.scene.gameObjects.size() };
        }

    private:
        EntityComponentSystem& m_EntityComponentSystem;
	};
}
