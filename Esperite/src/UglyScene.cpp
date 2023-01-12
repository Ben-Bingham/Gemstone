#include "UglyScene.h"

namespace Esperite {
	UglyGameObject UglyScene::newGameObject() {
		m_GameObjects.push_back(m_FurthestGameObject);
		m_FurthestGameObject++;
		return m_GameObjects.back();
	}
}
