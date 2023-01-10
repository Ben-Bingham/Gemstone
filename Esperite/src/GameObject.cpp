#include "GameObject.h"

#include "ComponentManager.h"
#include "Pointer.h"

namespace Esperite {
	void GameObject::addComponent(const Celestite::Ptr<Component>& component) {
		ComponentManager::get().addComponent(component);
		m_Components.push_back(component);
	}
}