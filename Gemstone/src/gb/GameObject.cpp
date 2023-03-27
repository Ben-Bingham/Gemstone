#include "pch.h"
#include "GameObject.h"

#include "Esperite/ECSScene.h"

namespace Gem {
	GameObject::GameObject()
		: m_Owner(activeScene), m_Handle(m_Owner->NewGameObject()) {
		
	}
}