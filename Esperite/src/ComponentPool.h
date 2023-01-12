#pragma once

#include <vector>

#include "GameObject.h"
#include "Log.h"

namespace Esperite {
	inline unsigned int masterComponentCounter{ 0 };

	template<typename T>
	unsigned int getId() {
		static unsigned int componentId = masterComponentCounter++;
		return componentId;
	}

	class IComponentPool {};

	template<typename T>
	class ComponentPool : public IComponentPool {
	public:
		ComponentPool() {
			m_Components.reserve(10);
		}

		bool hasComponent(const GameObject gb) {
			if (m_Sparse.size() < gb + 1) {
				m_Sparse.resize(gb + 1);
			}

			const size_t denseIndex = m_Sparse[gb];

			if (denseIndex + 1 > m_Dense.size()) {
				return false;
			}

			return m_Dense[denseIndex] == gb;
		}

		[[nodiscard]] T* getComponent(const GameObject gb) {
			if (!hasComponent(gb)) {
				return nullptr;
			}

			const size_t index = m_Sparse[gb];

			return &m_Components[index];
		}

		T* addAndGet(const GameObject gb) {
#ifdef ESPERITE_DEBUG
			if (hasComponent(gb)) { //TODO the checks should only be called once, either in scene class or in component pool,
				// it is debug tho so maybe its fine
				LOG("Entity already has component", Lazuli::LogLevel::WARNING);
			}
#endif

			if (m_NextComponent + 1 > m_Dense.size()) {
				m_Dense.resize(m_NextComponent + 1);
			}

			if (gb + 1 > m_Sparse.size()) {
				m_Sparse.resize(gb + 1);
			}

			m_Dense[m_NextComponent] = gb;
			m_Sparse[gb] = m_NextComponent;

			m_NextComponent++;

			m_Components.push_back(T());

			const size_t index = m_Sparse[gb];

			return &m_Components[index]; //TODO replace last part with a call the the getComponentFunctin
		}

		void removeComponent(const GameObject gb) { //TODO does not work and shouldent
#ifdef ESPERITE_DEBUG
			if (!hasComponent(gb)) { //TODO the checks should only be called once, either in scene class or in component pool,
				// it is debug tho so maybe its fine
				LOG("Entity already dosent have component", Lazuli::LogLevel::WARNING);
			}
#endif
			GameObjectType temp = m_Dense[m_NextComponent - 1];
			m_Dense[m_Sparse[gb]] = temp;
			m_Sparse[temp] = sparse[gb];
		}

		unsigned int id{ 0 };

	private:
		std::vector<GameObjectType> m_Sparse{ };
		std::vector<GameObjectType> m_Dense{ };
		std::vector<T> m_Components;
		GameObjectType m_NextComponent{ 0 };
	};
}