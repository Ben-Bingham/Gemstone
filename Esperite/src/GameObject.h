#pragma once

#include <limits>

namespace Esperite {
	using GameObjectType = unsigned int;
	using GameObject = GameObjectType;

	constexpr GameObjectType MAX_ENTITIES = std::numeric_limits<GameObjectType>::max();
	constexpr size_t MAX_COMPONENT_TYPES{ 256 };
	constexpr size_t MAX_COMPONENTS_PER_TYPE{ 10000 };
}