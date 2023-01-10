#include "ComponentManager.h"

#include <typeindex>

namespace Emerald {
	ComponentManager& ComponentManager::get() {
		static ComponentManager manager;
		return manager;
	}

	void ComponentManager::addComponent(const Celestite::Ptr<Component>& component) {
		bool found = false;
		int i = 0;
		for (Celestite::Ptr<Component> comp : m_Components) {
			if (std::type_index(typeid(*component)) == std::type_index(typeid(*comp))) {
				found = true;

				m_Components.insert(m_Components.begin() + i + 1, component);
				break;
			}

			i++;
		}

		if (!found) {
			m_Components.push_back(component);
		}
	}
}