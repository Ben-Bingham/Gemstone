#include "pch.h"
#include "Game.h"

namespace Gem {
	Game::Game(Engine_New& engine)
		: levelManager(engine) {
		
	}

	void Game::Run() {
		levelManager.RunLevels();
	}
}