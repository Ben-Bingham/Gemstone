#pragma once
#include "Window.h"
#include <functional>
#include "Entity Component System/EntityComponentSystem.h"
#include "Gem.h"
#include "Level.h"

namespace Gem {
	/*
	 * The Game class is the actual runtime of the game itself, it needs to be manually Run by the user in order for the game to start.
	 */
	class Game {
	public:
		Game(Engine& engine);

		using ConditionFunction = std::function<bool(Ptr<Level> level)>;
		void Run(Ptr<Level> level, ConditionFunction conditionFunction = [](Ptr<Level> level)->bool { return true; });

		Engine& engine;

		EntityComponentSystem ecs;

	private:
		double DelayFrame(double frameStartTime);
	};
}
