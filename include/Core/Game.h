#pragma once
#include <functional>
#include "Engine.h"
#include "Entity Component System/EntityComponentSystem.h"
#include "Level.h"
#include "Utility/Time.h"

namespace Gem {
	/*
	 * The Game class is the actual runtime of the game itself, it needs to be manually Run by the user in order for the game to start.
	 */
	class Game {
	public:
		Game(Engine& engine);

		using ConditionFunction = std::function<bool(Ptr<Level> level)>;
		// Level will run, as long as the condition function returns true.
		void Run(Ptr<Level> level, ConditionFunction conditionFunction = [](Ptr<Level> level)->bool { return true; });

		Engine& engine;

	private:
		float DelayFrame(float frameStartTime) const;

		Time m_TimeManager;
	};
}
