#pragma once
#include "Entity Component System/EntityComponentSystem.h"

namespace Gem {
	class Engine;

	class Level {
	public:
		Level() = default;

		EntityComponentSystem ecs;
	};
}