#pragma once
#include "LevelManager.h"

namespace Gem {
	/*
	 * The Game class is the actual runtime of the game itself, it needs to be manually Run by the user in order for the game to start.
	 */
	class Game {
	public:
		Game(Engine_New& engine);

		void Run();

		LevelManager levelManager;
	};
}