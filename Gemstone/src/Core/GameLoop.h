#pragma once
#include "Engine_New.h"
#include "Level_New.h"

#include "Utility/Pointer.h"

namespace Gem {
	/*
	 * Controls the game loop for any level
	 */
	class GameLoop {
	public:
		GameLoop(Engine_New& engine);

		void Loop(Ptr<Level_New>& level);

	private:
		void DoubleFrameRateUpdate(Ptr<Level_New>& level);		// Is called twice every frame, follows FPS
		void FrameRateUpdate(Ptr<Level_New>& level);			// Is called every frame, follows FPS
		void HalfFrameRateUpdate(Ptr<Level_New>& level);		// Is called every other frame, follows FPS
		void SecondUpdate(Ptr<Level_New>& level);				// Is called once every second
		void HalfSecondUpdate(Ptr<Level_New>& level);			// Is called every half second

		Engine_New& m_Engine;
		bool m_LockFrameRate{ true };

		int m_DoubleFrameRateCounter{ 0 }; // Is incremented twice per frame, so it keeps track of twice the frame count.
		int m_HalfSecondCounter{ 0 };
	};
}