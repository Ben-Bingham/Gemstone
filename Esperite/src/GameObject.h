#pragma once

#include <limits>

namespace Esperite {
	using GameObjectType = unsigned int;
	using GameObject = GameObjectType;

	constexpr GameObjectType MAX_ENTITIES = std::numeric_limits<GameObjectType>::max();
}