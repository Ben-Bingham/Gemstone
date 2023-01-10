#pragma once
#include <typeindex>
#include <vector>

#include "Component.h"
#include "Pointer.h"

namespace Esperite {
	class ComponentManager {
	public:
		ComponentManager(const ComponentManager& other) = delete;
		ComponentManager(ComponentManager&& other) noexcept = delete;
		ComponentManager& operator=(const ComponentManager& other) = delete;
		ComponentManager& operator=(ComponentManager&& other) noexcept = delete;

		static ComponentManager& get();

		void addComponent(const Celestite::Ptr<Component>& component);

		template<typename T>
		std::pair<typename std::vector<Celestite::Ptr<T>>::iterator, typename std::vector<Celestite::Ptr<T>>::iterator> getComponents() {
			using IteratorT = typename std::vector<Celestite::Ptr<T>>::iterator;
			using Iterator = std::vector<Celestite::Ptr<Component>>::iterator;

			Iterator begin = m_Components.end(); //TODO why no work
			Iterator end;

			int i = 0;
			for (Celestite::Ptr<Component>& component : m_Components) {
				if (std::type_index(typeid(T)) == std::type_index(typeid(*component))) {
					begin = m_Components.begin() + i;
					break;
				}
				i++;
			}

			if (begin != m_Components.end()) {
				for (auto it = begin; it != m_Components.end(); ++it) {
					if (std::type_index(typeid(T)) != std::type_index(typeid(**it))) {
						end = it;
						break;
					}
				}
			}

			using Val = decltype(begin);

			return std::pair<IteratorT, IteratorT>{ *(IteratorT*)(void*)&begin, *(IteratorT*)(void*)&end };
		}

	private:
		ComponentManager() = default;

		std::vector<Celestite::Ptr<Component>> m_Components{};
	};
}
