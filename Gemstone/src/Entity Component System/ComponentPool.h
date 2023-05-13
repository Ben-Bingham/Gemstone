#pragma once

#include "Component.h"
#include "Entity.h"

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
		virtual void* operator[](Entity entity) = 0;
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
			return (*this)[entity];
		}

		void* operator[](const Entity entity) override {
			return m_ComponentMemory + entity * m_ComponentSize;
		}

	private:
		static inline const size_t m_ComponentSize{ sizeof(ComponentType) };
		unsigned char* m_ComponentMemory;
	};

// 	class ComponentPool {
// 	public:
// 		ComponentPool(size_t componentId, size_t componentSize);
//
// 		// Inserts and initializes the component into the given entity.
// 		template<typename ComponentType, typename ...Args>
// 		void Insert(Entity& entity, Args&&...args) {
// #ifdef GEMSTONE_DEBUG
// 			if (Has(entity)) {
// 				LOG("Entitys cannot have multiple of the same component. Entity with Id: " + std::to_string(entity.id) + " already has \"" + std::string(typeid(ComponentType).name()) + "\" component.", LogLevel::ERROR);
// 				return;
// 			}
// #endif
// 			entity.componentField.set(m_ComponentId);
//
// 			new (m_Components + m_ComponentSize * entity.id) ComponentType{ std::forward<Args>(args)... };
// 		}
//
// 		// Removes and destroys the component from the given entity.
// 		template<typename ComponentType>
// 		void Extract(Entity& entity) {
// #ifdef GEMSTONE_DEBUG
// 			if (!Has(entity)) {
// 				LOG("Cannot delete component from entity that does not have component: \"" + std::string(typeid(ComponentType).name()) + "\".", LogLevel::ERROR);
// 				return;
// 			}
// #endif
// 			entity.componentField.reset(m_ComponentId);
//
// 			reinterpret_cast<ComponentType*>(m_Components + m_ComponentSize * entity.id)->~ComponentType();
// 		}
//
// 		// Gets a pointer to the entities component.
// 		[[nodiscard]] void* Get(const Entity& entity) const;
//
// 		// Returns weather or not the entity has the component.
// 		[[nodiscard]] bool Has(const Entity& entity) const;
//
// 		// // Returns the component at the specified index, whether or not it exists.
// 		// ComponentType* operator[](const size_t index) {
// 		// 	return reinterpret_cast<ComponentType*>(m_Components + m_ComponentSize * index);
// 		// }
// 		// const ComponentType* operator[](const size_t index) const {
// 		// 	return reinterpret_cast<ComponentType*>(m_Components + m_ComponentSize * index);
// 		// }
//
// 		// Iterates all components regardless of there validity
// 		// class Iterator {
// 		// public:
// 		// 	using ValueType = ComponentType;
// 		// 	using Pointer = ValueType*;
// 		// 	using Reference = ValueType&;
// 		//
// 		// 	Iterator(const Pointer ptr)
// 		// 		: m_Pointer(ptr) {
// 		// 	}
// 		//
// 		// 	Reference operator*() { return *m_Pointer; }
// 		// 	Pointer operator->() { return m_Pointer; }
// 		//
// 		// 	Iterator& operator++() { ++m_Pointer; return *this; }
// 		//
// 		// 	friend bool operator==(const Iterator& lhs, const Iterator& rhs) { return lhs.m_Pointer == rhs.m_Pointer; }
// 		// 	friend bool operator!=(const Iterator& lhs, const Iterator& rhs) { return !(lhs == rhs); }
// 		//
// 		// private:
// 		// 	Pointer m_Pointer;
// 		// };
// 		//
// 		// Iterator begin() { return Iterator{ reinterpret_cast<ComponentType*>(m_Components) }; }
// 		// Iterator end() { return Iterator{ reinterpret_cast<ComponentType*>(m_Components + m_ComponentSize * MAX_ENTITIES) }; }
//
// 	private:
// 		const size_t m_ComponentId;
// 		const size_t m_ComponentSize;
// 		unsigned char* m_Components;
// 	};

// 	// Interface for component pools
// 	class IComponentPool {
// 	public:
// 		
// 	};
//
// 	template<typename ComponentType>
// 	class ComponentPool : public IComponentPool {
// 	public:
// 		ComponentPool()
// 			: m_Components(new unsigned char[sizeof(ComponentType) * MAX_ENTITIES]) { }
//
// 		// Inserts and initializes the component into the given entity.
// 		template<typename ...Args>
// 		void Insert(Entity& entity, Args&&...args) {
// #ifdef GEMSTONE_DEBUG
// 			if (Has(entity)) {
// 				LOG("Entitys cannot have multiple of the same component. Entity already has component \"" + std::string(typeid(ComponentType).name()) + "\".", LogLevel::ERROR);
// 				return;
// 			}
// #endif
// 			entity.componentField.set(m_ComponentId);
//
// 			new (m_Components + m_ComponentSize * entity.id) ComponentType{ std::forward<Args>(args)... };
// 		}
//
// 		// Returns a reference to the component. Only use if sure the component exists.
// 		[[nodiscard]] ComponentType& Get(const Entity& entity) {
// 			return *GetPointer(entity);
// 		}
//
// 		// Returns a pointer to the component, or nullptr if the entity does not have the component.
// 		[[nodiscard]] ComponentType* GetPointer(const Entity& entity) {
// 			if (!Has(entity)) {
// 				return nullptr;
// 			}
//
// 			return reinterpret_cast<ComponentType*>(m_Components + m_ComponentSize * entity.id);
// 		}
//
// 		// Returns weather or not the entity has the component.
// 		[[nodiscard]] static bool Has(const Entity& entity) {
// 			return entity.componentField[m_ComponentId];
// 		}
//
// 		// Removes and destroys the component from the given entity.
// 		void Extract(Entity& entity) {
// #ifdef GEMSTONE_DEBUG
// 			if (!Has(entity)) {
// 				LOG("Cannot delete component from entity that does not have component: \"" + std::string(typeid(ComponentType).name()) + "\".", LogLevel::ERROR);
// 				return;
// 			}
// #endif
// 			entity.componentField.reset(m_ComponentId);
//
// 			reinterpret_cast<ComponentType*>(m_Components + m_ComponentSize * entity.id)->~ComponentType();
// 		}
//
// 		// Returns the component at the specified index, whether or not it exists.
// 		ComponentType* operator[](const size_t index) {
// 			return reinterpret_cast<ComponentType*>(m_Components + m_ComponentSize * index);
// 		}
// 		const ComponentType* operator[](const size_t index) const {
// 			return reinterpret_cast<ComponentType*>(m_Components + m_ComponentSize * index);
// 		}
//
// 		// Iterates all components regardless of there validity
// 		class Iterator {
// 		public:
// 			using ValueType = ComponentType;
// 			using Pointer = ValueType*;
// 			using Reference = ValueType&;
// 		
// 			Iterator(const Pointer ptr)
// 				: m_Pointer(ptr) { }
// 		
// 			Reference operator*() { return *m_Pointer; }
// 			Pointer operator->() { return m_Pointer; }
// 		
// 			Iterator& operator++() { ++m_Pointer; return *this; }
// 		
// 			friend bool operator==(const Iterator& lhs, const Iterator& rhs) { return lhs.m_Pointer == rhs.m_Pointer; }
// 			friend bool operator!=(const Iterator& lhs, const Iterator& rhs) { return !(lhs == rhs); }
// 		
// 		private:
// 			Pointer m_Pointer;
// 		};
// 		
// 		Iterator begin() { return Iterator{ reinterpret_cast<ComponentType*>(m_Components) }; }
// 		Iterator end() { return Iterator{ reinterpret_cast<ComponentType*>(m_Components + m_ComponentSize * MAX_ENTITIES) }; }
//
// 	private:
// 		unsigned char* m_Components;
// 		static inline const size_t m_ComponentId{ ComponentId<ComponentType>() };
// 		static inline const size_t m_ComponentSize{ sizeof(ComponentType) };
// 	};
}