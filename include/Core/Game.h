#pragma once
#include <functional>
#include "Entity Component System/EntityComponentSystem.h"
#include "Level.h"
#include "Utility/Time.h"

namespace Gem {
	/*
	 * The Game class is the actual runtime of the game itself, it needs to be manually Run by the user in order for the game to start.
	 */
	class Game {
	public:
		Game() = default;

		using ConditionFunction = std::function<bool(Ptr<Level> level)>;
		// Level will run, as long as the condition function returns true. //TODO flip this
		void Run(Ptr<Level> level, ConditionFunction conditionFunction = [](Ptr<Level> level)->bool { return true; });

	private:
		float DelayFrame(float frameStartTime) const;

		Time m_TimeManager;
	};
}
