#pragma once
#include "GameLoop.h"
#include "Level_New.h"

#include "Utility/Pointer.h"

namespace Gem {
	/*
	 * Manager level flow
	 *
	 * TODO currently levels can only be loaded linearly, this should be changed.
	 */
	class LevelManager {
	public:
		LevelManager(Engine_New& engine);

		void AddLevel(Ptr<Level_New> level);

		[[nodiscard]] bool HasLevels() const;

		Ptr<Level_New> GetLevel();

	private:
		std::vector<Ptr<Level_New>> m_Levels;
		GameLoop m_GameLoop;
	};
}