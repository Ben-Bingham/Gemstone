#pragma once
#include "Entity Component System/EntityComponentSystem.h"

namespace Gem {
	class Engine;

	class Level {
	public:
		Level(Engine& engine); //TODO does this need to be mandatory?

		Engine& engine;
		EntityComponentSystem ecs;
	};
}