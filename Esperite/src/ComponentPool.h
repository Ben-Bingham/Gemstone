#pragma once

#include <vector>
#include <array>

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
		IComponentPool(const IComponentPool& other) = default;
		IComponentPool(IComponentPool&& other) noexcept = default;
		IComponentPool& operator=(const IComponentPool& other) = default;
		IComponentPool& operator=(IComponentPool&& other) noexcept = default;
		virtual ~IComponentPool() = default;
	
		virtual void AddComponent(GameObject gb) = 0;
		[[nodiscard]] virtual void* GetComponent(GameObject gb) const = 0;
		[[nodiscard]] virtual bool HasComponent(GameObject gb) const = 0;
	};

	class ComponentPool final : public IComponentPool {
	public:
		ComponentPool(const size_t componentSize)
			: m_ComponentSize(componentSize) {

			m_Components = new char[m_ComponentSize * MAX_COMPONENTS_PER_TYPE];
		}

		~ComponentPool() override {
			delete[] m_Components;
		}

		[[nodiscard]] bool HasComponent(const GameObject gb) const override {
			if (gb + 1 > m_Sparse.size()) {
				return false;
			}

			const size_t denseIndex = m_Sparse[gb];

			if (denseIndex + 1 > m_Dense.size()) {
				return false;
			}

			return m_Dense[denseIndex] == gb;
		}

		[[nodiscard]] void* GetComponent(const GameObject gb) const override { //TODO testing needed, this is almost a carbon copy of the has component function
			if (gb + 1 > m_Sparse.size()) {									   //TODO can a lot of it be replaced with a call to it or is that slower?
				return nullptr;
			}

			const size_t denseIndex = m_Sparse[gb];

			if (denseIndex + 1 > m_Dense.size()) {
				return nullptr;
			}

			if(m_Dense[denseIndex] == gb) {
				return m_Components + denseIndex * m_ComponentSize;
			}

			return nullptr;
		}

		void AddComponent(GameObject gb) override {
// #ifdef ESPERITE_DEBUG
// 			if (hasComponent(gb)) { //TODO the checks should only be called once, either in scene class or in component pool,
// 				// it is debug tho so maybe its fine
// 				LOG("Entity already has component", Lazuli::LogLevel::WARNING);
// 			}
// #endif

			// if (m_NextComponent + 1 > m_Dense.size()) {
			// 	m_Dense.resize(m_NextComponent + 1);
			// 	// m_Components.resize(m_NextComponent + 1);
			// }
			//
			// if (gb + 1 > m_Sparse.size()) {
			// 	m_Sparse.resize(gb + 1);
			// }

			m_Dense.resize(m_LastComponent + 2);
			m_Sparse.resize(gb + 1);

			m_Dense[m_LastComponent + 1] = gb;
			m_Sparse[gb] = m_LastComponent + 1;


			// m_Components.push_back(T());

			// if (m_NextComponent != m_Components.size()) {
			// 	m_Components.resize(m_Dense.size());
			// }

			m_LastComponent++;

			// m_Components.push_back(T());

			// const size_t index = m_Sparse[gb];

			// return &m_Components[index]; //TODO replace last part with a call the the getComponentFunctin
		}

// 		void removeComponent(const GameObject gb) { //TODO does not work and shouldent
// #ifdef ESPERITE_DEBUG
// 			if (!hasComponent(gb)) { //TODO the checks should only be called once, either in scene class or in component pool,
// 				// it is debug tho so maybe its fine
// 				LOG("Entity already dosent have component", Lazuli::LogLevel::WARNING);
// 			}
// #endif
//
// 			if (m_Dense.size() == 1) {
// 				
// 			}
//
// 			const size_t denseIndex = m_Sparse[gb];
// 			const GameObjectType backItem = m_Dense[m_NextComponent - 1];
// 			m_Dense[denseIndex] = backItem;
// 			m_Sparse[backItem] = (GameObjectType)denseIndex;
//
// 			// const size_t oldCompIndex = backItem;
// 			// const size_t newCompIndex = m_Dense[denseIndex];
//
// 			m_Components[denseIndex] = m_Components[m_NextComponent - 1];
//
// 			m_NextComponent--;
//
// 			m_Dense.resize(m_Dense.size() - 1);
// 			m_Components.resize(m_Components.size() - 1);
// 		}
		
		unsigned int id{ 0 };

	private:
		std::vector<GameObjectType> m_Sparse{ };
		std::vector<GameObjectType> m_Dense{ };
		// GameObjectType m_NextComponent{ 0 };
		int m_LastComponent{ -1 };
		size_t m_ComponentSize;
		char* m_Components;
	};
}