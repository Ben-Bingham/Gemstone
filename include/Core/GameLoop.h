#pragma once
#include "Engine_New.h"
#include "Level_New.h"
#include "Window_New.h"

#include "Utility/Pointer.h"
#include "Gem.h"

namespace Gem {
	/*
	 * Controls the game loop for any level
	 */
	class GEM_API GameLoop {
	public:
		GameLoop(Engine_New& engine);

		void Loop(Ptr<Level_New>& level);

		void SetWindow(Window_New* window);

	private:
		void DoubleFrameRateUpdate(Ptr<Level_New>& level);		// Is called twice every frame, follows FPS
		void FrameRateUpdate(Ptr<Level_New>& level);			// Is called every frame, follows FPS
		void HalfFrameRateUpdate(Ptr<Level_New>& level);		// Is called every other frame, follows FPS
		void SecondUpdate(Ptr<Level_New>& level);				// Is called once every second
		void HalfSecondUpdate(Ptr<Level_New>& level);			// Is called every half second

		Engine_New& m_Engine;
		bool m_LockFrameRate{ true };
//<<<<<<< HEAD

		Window_New* m_Window;
//=======
//>>>>>>> c45902e481ceeaa56edb35b99852a647fa53ac3e

		int m_DoubleFrameRateCounter{ 0 }; // Is incremented twice per frame, so it keeps track of twice the frame count.
		int m_HalfSecondCounter{ 0 };
	};
}