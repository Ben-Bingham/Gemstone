#pragma once

#include <array>
#include <bitset>
#include <vector>

#include "InternalGameObject.h"

namespace Gem {
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
	
		virtual void AddComponent(InternalGameObject gb) = 0;
		[[nodiscard]] virtual void* GetComponent(InternalGameObject gb) = 0;
		[[nodiscard]] virtual bool HasComponent(InternalGameObject gb) const = 0;
	};

	class FixedSizeSparseSetComponentPool : public IComponentPool {
	public:
		FixedSizeSparseSetComponentPool(const size_t componentSize)
			: m_ComponentSize(componentSize) {

			m_Components = new char[m_ComponentSize * MAX_COMPONENTS_PER_TYPE];
		}

		~FixedSizeSparseSetComponentPool() override {
			delete[] m_Components;
		}

		[[nodiscard]] bool HasComponent(const InternalGameObject gb) const override {
			if ((int)m_Sparse[gb] > m_LastComponent){
				return false;
			}

			return m_Dense[m_Sparse[gb]] == gb;
		}

		[[nodiscard]] void* GetComponent(const InternalGameObject gb) override {
			return m_Components + m_Sparse[gb] * m_ComponentSize;
		}

		void AddComponent(InternalGameObject gb) override {
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

		[[nodiscard]] bool HasComponent(const InternalGameObject gb) const override {
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

		[[nodiscard]] void* GetComponent(const InternalGameObject gb) override {
			if (gb + 1 < m_Sparse.size()) {
				m_Sparse.resize(gb + 1);
			}

			return m_Components + m_Sparse[gb] * m_ComponentSize;
		}

		void AddComponent(const InternalGameObject gb) override {
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
		using BitSet = std::bitset<MAX_COMPONENT_TYPES>;
	public:
		FixedSizeBitSetComponentPool(const size_t componentSize, const size_t id)
			: m_ComponentSize(componentSize), m_Id(id) {

			m_Components = new char[componentSize * MAX_COMPONENTS_PER_TYPE];
		}

		~FixedSizeBitSetComponentPool() override {
			delete[] m_Components;
		}

		void AddComponent(InternalGameObject gb) override {
			m_BitSets[gb].set(m_Id);
		}

		[[nodiscard]] void* GetComponent(InternalGameObject gb) override {
			return m_Components + gb * m_ComponentSize;
		}

		[[nodiscard]] bool HasComponent(InternalGameObject gb) const {
			return m_BitSets[gb].test(m_Id);
		}

	private:
		inline static std::array<BitSet, MAX_GAME_OBJECTS> m_BitSets{};
		char* m_Components;
		size_t m_ComponentSize;
		size_t m_Id;
	};
}