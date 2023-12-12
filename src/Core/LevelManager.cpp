#include "pch.h"
#include "Core/LevelManager.h"

namespace Gem {
	LevelManager::LevelManager(Engine_New& engine)
		: m_GameLoop(engine) {
		
	}

	void LevelManager::AddLevel(Ptr<Level_New> level) {
		m_Levels.push_back(std::move(level));
	}

	bool LevelManager::HasLevels() const {
		return !m_Levels.empty();
	}

	Ptr<Level_New> LevelManager::GetLevel() {
		return m_Levels.back();
	}
}