#include "pch.h"
#include "ECSScene.h"
#include "System.h"

#include "gb/GameObject.h"

#include "Lazuli/Log.h"

namespace Esperite {
	ECSScene::ECSScene() {
		Gem::GameObject::activeScene = this;
		System::activeScene = this;
	}
}