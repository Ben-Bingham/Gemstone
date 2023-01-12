#pragma once

#include <limits>

#include "SceneManager.h"

namespace Esperite {
	using GameObjectType = unsigned int;
	using UglyGameObject = GameObjectType;

	constexpr GameObjectType MAX_ENTITIES = std::numeric_limits<GameObjectType>::max();
}