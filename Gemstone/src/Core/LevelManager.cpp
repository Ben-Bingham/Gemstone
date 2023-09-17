#include "pch.h"
#include "LevelManager.h"

namespace Gem {
	LevelManager::LevelManager(Engine_New& engine)
		: m_GameLoop(engine) {
		
	}

	void LevelManager::AddLevel(Ptr<Level_New> level) {
		m_Levels.push_back(std::move(level));
	}

	void LevelManager::RunLevels() {
		for (auto& level : m_Levels) {
			m_GameLoop.Loop(level);
		}
	}
}