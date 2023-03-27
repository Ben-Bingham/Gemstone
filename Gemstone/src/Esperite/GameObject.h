#pragma once

namespace Esperite {
	using GameObjectType = unsigned int;
	using InternalGameObject = GameObjectType;

	constexpr GameObjectType MAX_GAME_OBJECTS{ 999999 };
	constexpr InternalGameObject NULL_GAME_OBJECT = InternalGameObject{ MAX_GAME_OBJECTS + 1 };
	constexpr size_t MAX_COMPONENT_TYPES{ 256 };
	constexpr size_t MAX_COMPONENTS_PER_TYPE{ MAX_GAME_OBJECTS };
}