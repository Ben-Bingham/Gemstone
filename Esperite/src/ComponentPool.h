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

	class IComponentPool {
	public:
		IComponentPool() = default;

		virtual ~IComponentPool() = default;
	};

	template<typename T>
	class ComponentPool : public IComponentPool {
	public:
		ComponentPool() {
			LOG("Pool created");
			m_Components.reserve(10);
		}

		~ComponentPool() {
			LOG("Pool destroyed");
		}

		[[nodiscard]] bool hasComponent(const GameObject gb) const {
			if (m_Sparse.size() < gb + 1) {
				return false;
			}
			// if (gb >= m_NextComponent) {
			// 	return false;
			// }

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

		template<typename ...G>
		T* addAndGet(const GameObject gb, G&& ...args) {
#ifdef ESPERITE_DEBUG
			if (hasComponent(gb)) { //TODO the checks should only be called once, either in scene class or in component pool,
				// it is debug tho so maybe its fine
				LOG("Entity already has component", Lazuli::LogLevel::WARNING);
			}
#endif

			if (m_NextComponent + 1 > m_Dense.size()) {
				m_Dense.resize(m_NextComponent + 1);
				// m_Components.resize(m_NextComponent + 1);
			}

			if (gb + 1 > m_Sparse.size()) {
				m_Sparse.resize(gb + 1);
			}

			m_Dense[m_NextComponent] = gb;
			m_Sparse[gb] = m_NextComponent;


			m_Components.push_back(T(args...));

			// if (m_NextComponent != m_Components.size()) {
			// 	m_Components.resize(m_Dense.size());
			// }

			m_NextComponent++;

			// m_Components.push_back(T());

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

			if (m_Dense.size() == 1) {
				
			}

			const size_t denseIndex = m_Sparse[gb];
			const GameObjectType backItem = m_Dense[m_NextComponent - 1];
			m_Dense[denseIndex] = backItem;
			m_Sparse[backItem] = (GameObjectType)denseIndex;

			// const size_t oldCompIndex = backItem;
			// const size_t newCompIndex = m_Dense[denseIndex];

			m_Components[denseIndex] = m_Components[m_NextComponent - 1];

			m_NextComponent--;

			m_Dense.resize(m_Dense.size() - 1);
			m_Components.resize(m_Components.size() - 1);
		}

		unsigned int id{ 0 };

	private:
		std::vector<GameObjectType> m_Sparse{ };
		std::vector<GameObjectType> m_Dense{ };
		std::vector<T> m_Components;
		GameObjectType m_NextComponent{ 0 };
	};
}