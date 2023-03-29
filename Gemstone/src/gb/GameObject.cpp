#include "pch.h"
#include "GameObject.h"

#include "Esperite/Scene.h"

namespace Gem {
	GameObject::GameObject(EntityComponentSystem& owner, const InternalGameObject handle)
		: m_Owner(owner), m_Handle(handle) {

	}

	GameObject::GameObject(EntityComponentSystem& owner)
		: m_Owner(owner), m_Handle(m_Owner.scene.NewGameObject()) {

	}
}