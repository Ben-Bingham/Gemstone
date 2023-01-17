#pragma once

#include <limits>

namespace Esperite {
	using GameObjectType = unsigned int;
	using GameObject = GameObjectType;

	constexpr GameObjectType MAX_ENTITIES{ 10000 };
	constexpr size_t MAX_COMPONENT_TYPES{ 256 };
	constexpr size_t MAX_COMPONENTS_PER_TYPE{ MAX_ENTITIES };
}