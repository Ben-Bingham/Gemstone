#pragma once

#include "Component.h"
#include "EntityManager.h"
#include "Gem.h"

namespace Gem {
	class IComponentPool {
	public:
		IComponentPool() = default;
		IComponentPool(const IComponentPool& other) = default;
		IComponentPool(IComponentPool&& other) noexcept = default;
		IComponentPool& operator=(const IComponentPool& other) = default;
		IComponentPool& operator=(IComponentPool&& other) noexcept = default;
		virtual ~IComponentPool() = default;

		virtual void* Get(Entity entity) = 0;
	};

	template<typename ComponentType>
	class ComponentPool final : public IComponentPool {
	public:
		ComponentPool()
			: IComponentPool()
			, m_ComponentMemory(new unsigned char[MAX_ENTITIES * m_ComponentSize]) { }

		ComponentPool(const ComponentPool& other) = delete;
		ComponentPool(ComponentPool&& other) noexcept = default;
		ComponentPool& operator=(const ComponentPool& other) = delete;
		ComponentPool& operator=(ComponentPool&& other) noexcept = default;

		~ComponentPool() override {
			delete[] m_ComponentMemory;
		}

		void* Get(const Entity entity) override {
			return m_ComponentMemory + entity * m_ComponentSize;
		}

	private:
		static inline const size_t m_ComponentSize{ sizeof(ComponentType) };
		unsigned char* m_ComponentMemory;
	};
}