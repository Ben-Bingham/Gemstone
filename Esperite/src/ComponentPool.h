#pragma once

#include <vector>

#include "UglyGameObject.h"
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

		bool hasComponent(const UglyGameObject gb) {
			if (m_Sparse.size() < gb + 1) {
				m_Sparse.resize(gb + 1);
			}

			const size_t denseIndex = m_Sparse[gb];

			if (denseIndex + 1 > m_Dense.size()) {
				return false;
			}

			return m_Dense[denseIndex] == gb;
		}

		[[nodiscard]] T* getComponent(const UglyGameObject gb) {
			if (!hasComponent(gb)) {
				return nullptr;
			}

			const size_t index = m_Sparse[gb];

			return &m_Components[index];
		}

		T* addAndGet(const UglyGameObject gb) {
#ifdef ESPERITE_DEBUG
			if (hasComponent(gb)) {
				LOG("Entity already has component", Lazuli::LogLevel::WARNING);
			}
#endif

			if (m_NextComponent + 1 > m_Dense.size()) {
				m_Dense.resize(m_NextComponent + 1);
			}

			m_Dense[m_NextComponent] = gb;
			m_Sparse[gb] = m_NextComponent;

			m_NextComponent++;

			m_Components.push_back(T());

			const size_t index = m_Sparse[gb];

			return &m_Components[index];
		}

		unsigned int id{ 0 };

	private:
		std::vector<GameObjectType> m_Sparse{ };
		std::vector<GameObjectType> m_Dense{ };
		std::vector<T> m_Components;
		GameObjectType m_NextComponent{ 0 };
	};
}