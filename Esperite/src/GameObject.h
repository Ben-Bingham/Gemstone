#pragma once

#include <limits>

namespace Esperite {
	using GameObjectType = unsigned int;
	using GameObject = GameObjectType;

	constexpr GameObjectType MAX_GAME_OBJECTS{ 999999 };
	constexpr GameObject NULL_GAME_OBJECT = GameObject{ MAX_GAME_OBJECTS + 1 };
	constexpr size_t MAX_COMPONENT_TYPES{ 256 };
	constexpr size_t MAX_COMPONENTS_PER_TYPE{ MAX_GAME_OBJECTS };
}