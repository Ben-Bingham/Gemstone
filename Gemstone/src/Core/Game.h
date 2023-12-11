#pragma once
#include "LevelManager.h"
#include "Window_New.h"
#include <functional>
#include "Entity Component System/EntityComponentSystem.h"
#include "Gem.h"

namespace Gem {
	/*
	 * The Game class is the actual runtime of the game itself, it needs to be manually Run by the user in order for the game to start.
	 */
	GEM_API class Game {
	public:
		Game(Engine_New& engine);

		using ConditionFunction = std::function<bool(Ptr<Level_New> level)>;
		void Run(Ptr<Level_New> level, ConditionFunction conditionFunction = [](Ptr<Level_New> level)->bool { return true; });

		LevelManager levelManager;
		Window_New window;
		GameLoop gameLoop;
		Engine_New& engine;

		EntityComponentSystem ecs;

	private:
		double DelayFrame(double frameStartTime);
	};
}
