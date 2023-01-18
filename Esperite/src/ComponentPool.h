#pragma once

#include <vector>
#include <array>
#include <bitset>

#include "GameObject.h"
#include "Log.h"

namespace Esperite {
	inline unsigned int masterComponentCounter{ 0 };

	template<typename T>
	size_t getId() {
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
		[[nodiscard]] virtual void* GetComponent(GameObject gb) = 0;
		[[nodiscard]] virtual bool HasComponent(GameObject gb) const = 0;
	};

	class SparseSetComponentPool final : public IComponentPool {
	public:
		SparseSetComponentPool(const size_t componentSize)
			: m_ComponentSize(componentSize) {

			m_Components = new char[m_ComponentSize * MAX_COMPONENTS_PER_TYPE];
		}

		~SparseSetComponentPool() override {
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

		[[nodiscard]] void* GetComponent(const GameObject gb) override { //TODO testing needed, this is almost a carbon copy of the has component function
			if (gb + 1 > m_Sparse.size()) {									   //TODO can a lot of it be replaced with a call to it or is that slower?
				m_Sparse.resize(gb + 1);
			}

			//const size_t denseIndex = m_Sparse[gb];

			//if (denseIndex + 1 > m_Dense.size()) {
			//	return nullptr;
			//}

			//if(m_Dense[denseIndex] == gb) {
			//	return m_Components + denseIndex * m_ComponentSize;
			//}

			//return nullptr;

			if (!HasComponent(gb)) {
				AddComponent(gb);
			}

			return m_Components + m_Sparse[gb] * m_ComponentSize;
		}

//		template<typename T>
		void AddComponent(GameObject gb) override {
//// #ifdef ESPERITE_DEBUG
//// 			if (hasComponent(gb)) {
//// 				// it is debug tho so maybe its fine
//// 				LOG("Entity already has component", Lazuli::LogLevel::WARNING);
//// 			}
//// #endif
//
//			// if (m_NextComponent + 1 > m_Dense.size()) {
//			// 	m_Dense.resize(m_NextComponent + 1);
//			// 	// m_Components.resize(m_NextComponent + 1);
//			// }
//			//
//			// if (gb + 1 > m_Sparse.size()) {
//			// 	m_Sparse.resize(gb + 1);
//			// }
//
			m_Dense.resize(m_LastComponent + 2);
			m_Sparse.resize(gb + 1);

			m_Dense[m_LastComponent + 1] = gb;
			m_Sparse[gb] = m_LastComponent + 1;
//
//
//			// m_Components.push_back(T());
//
//			// if (m_NextComponent != m_Components.size()) {
//			// 	m_Components.resize(m_Dense.size());
//			// }
//
			m_LastComponent++;
//
//			// m_Components.push_back(T());
//
//			// const size_t index = m_Sparse[gb];
//
//			// return &m_Components[index]; //TODO replace last part with a call the the getComponentFunctin
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

	class FixedSizeSparseSetComponentPool final : public IComponentPool {
	public:
		FixedSizeSparseSetComponentPool(const size_t componentSize)
			: m_ComponentSize(componentSize) {

			m_Components = new char[m_ComponentSize * MAX_COMPONENTS_PER_TYPE];
		}

		~FixedSizeSparseSetComponentPool() override {
			delete[] m_Components;
		}

		[[nodiscard]] bool HasComponent(const GameObject gb) const override {
			if ((int)m_Sparse[gb] > m_LastComponent){
				return false;
			}

			return m_Dense[m_Sparse[gb]] == gb;
		}

		[[nodiscard]] void* GetComponent(const GameObject gb) override {
			return m_Components + m_Sparse[gb] * m_ComponentSize;
		}

		void AddComponent(GameObject gb) override {
			m_Dense[m_LastComponent + 1] = gb;
			m_Sparse[gb] = m_LastComponent + 1;

			m_LastComponent++;
		}

	private:
		std::array<GameObjectType, MAX_GAME_OBJECTS> m_Sparse{ };
		std::array<GameObjectType, MAX_GAME_OBJECTS> m_Dense{ };
		int m_LastComponent{ -1 };
		size_t m_ComponentSize;
		char* m_Components;
	};

	class VariableSizeSparseSetComponentPool : public IComponentPool {
	public:
		VariableSizeSparseSetComponentPool(const size_t componentSize)
			: m_ComponentSize(componentSize) {

			m_Components = new char[m_ComponentSize * MAX_COMPONENTS_PER_TYPE];
		}

		~VariableSizeSparseSetComponentPool() override {
			delete[] m_Components;
		}

		[[nodiscard]] bool HasComponent(const GameObject gb) const override {
			if (gb + 1 > m_Sparse.size()) {
				return false;
			}

			if ((int)m_Sparse[gb] > m_LastComponent) {
				return false;
			}

			const size_t denseIndex = m_Sparse[gb];

			if (denseIndex + 1 > m_Dense.size()) {
				return false;
			}

			return m_Dense[m_Sparse[gb]] == gb;
		}

		[[nodiscard]] void* GetComponent(const GameObject gb) override {
			if (gb + 1 < m_Sparse.size()) {
				m_Sparse.resize(gb + 1);
			}

			return m_Components + m_Sparse[gb] * m_ComponentSize;
		}

		void AddComponent(const GameObject gb) override {
			if (gb + 1 < m_Sparse.size()) {
				m_Sparse.resize(gb + 1);
			}
			size_t val = m_LastComponent + 2;
			bool test = val < m_Dense.size(); //TODO what the hell

			if (m_LastComponent + 2 < (int)m_Dense.size()) {
				m_Dense.resize(m_LastComponent + 2);
			}

			m_Dense[m_LastComponent + 1] = gb;
			m_Sparse[gb] = m_LastComponent + 1;

			m_LastComponent++;
		}

	private:
		std::vector<GameObjectType> m_Sparse{ };
		std::vector<GameObjectType> m_Dense{ };
		int m_LastComponent{ -1 };
		size_t m_ComponentSize;
		char* m_Components;
	};

	class FixedSizeBitSetComponentPool : public IComponentPool {
	private:
		using BitSet = std::bitset<MAX_COMPONENT_TYPES>;
	public:
		FixedSizeBitSetComponentPool(const size_t componentSize, const size_t id)
			: m_ComponentSize(componentSize), m_Id(id) {

			m_Components = new char[componentSize * MAX_COMPONENTS_PER_TYPE];
		}

		~FixedSizeBitSetComponentPool() override {
			delete[] m_Components;
		}

		void AddComponent(GameObject gb) override {
			m_BitSets[gb].set(m_Id);
		}

		[[nodiscard]] void* GetComponent(GameObject gb) override {
			return m_Components + gb * m_ComponentSize;
		}

		[[nodiscard]] bool HasComponent(GameObject gb) const {
			return m_BitSets[gb].test(m_Id);
		}

	private:
		inline static std::array<BitSet, MAX_GAME_OBJECTS> m_BitSets{};
		char* m_Components;
		size_t m_ComponentSize;
		size_t m_Id;
	};
}