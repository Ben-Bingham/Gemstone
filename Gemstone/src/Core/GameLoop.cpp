#include "pch.h"
#include "GameLoop.h"
#include "Engine.h"
#include "Math/FloatingPointMath.h"

namespace Gem {
	GameLoop::GameLoop(Engine_New& engine)
		: m_Engine(engine) {
	}

	void GameLoop::Loop(Ptr<Level_New>& level) {
		constexpr int fps = 60;
		using namespace std::chrono_literals;
		using namespace std::chrono;

		constexpr milliseconds frameTime = (milliseconds)(int)(1.0f / (float)fps);
		constexpr milliseconds halfFrameTime = frameTime / 2;


		while (level->running) {
			//const float loopStartTime = g_Engine.humanInterfaceDeviceContext.GetTime();
			const milliseconds loopStartTime = std::chrono::duration_cast<milliseconds>(m_Engine.time.GetElapsedTime());

			DoubleFrameRateUpdate(level);
			m_DoubleFrameRateCounter++;

			if (m_DoubleFrameRateCounter % 2 == 0) {
				FrameRateUpdate(level);
			}

			if (m_DoubleFrameRateCounter % 4 == 0) {
				HalfFrameRateUpdate(level);
			}

			if (m_LockFrameRate) {
				// If frame rate is locked, than we can easily run second, and half second updates based off number of frames run.
				if (m_DoubleFrameRateCounter % fps == 0) { // Because we loop at double the FPS this is only called every half second.
					HalfSecondUpdate(level);
				}

				if (m_DoubleFrameRateCounter % (fps * 2) == 0) {
					SecondUpdate(level);
				}

				// Wait until half a frame time has passed.
				//float frameTimeSoFar = g_Engine.humanInterfaceDeviceContext.GetTime() - loopStartTime;
				milliseconds frameTimeSoFar = std::chrono::duration_cast<milliseconds>(m_Engine.time.GetElapsedTime()) - loopStartTime;

				/*if (frameTimeSoFar > halfFrameTime) {
					frameTimeSoFar -= std::floor(frameTimeSoFar / halfFrameTime);
				}*/
				if (frameTimeSoFar > halfFrameTime) {
					frameTimeSoFar -= (milliseconds)(frameTimeSoFar / halfFrameTime);
				}

				//g_Engine.humanInterfaceDeviceContext.Wait(halfFrameTime - frameTimeSoFar);
				m_Engine.time.Wait(halfFrameTime - frameTimeSoFar);
			}
			else {
				/*if (EqualEnough(g_Engine.humanInterfaceDeviceContext.GetTime() / 0.5f, (float)m_HalfSecondCounter, 0.6f)) {
					m_HalfSecondCounter++;
					HalfSecondUpdate(level);

					if (m_HalfSecondCounter % 2 == 0) {
						SecondUpdate(level);
					}
				}*/
				if (EqualEnough((milliseconds)(m_Engine.time.GetElapsedTime() / 500ms), (milliseconds)m_HalfSecondCounter, 600ms)) {
					m_HalfSecondCounter++;
					HalfSecondUpdate(level);

					if (m_HalfSecondCounter % 2 == 0) {
						SecondUpdate(level);
					}
				}
			}
		}
	}

	void GameLoop::DoubleFrameRateUpdate(Ptr<Level_New>& level) {

	}

	void GameLoop::FrameRateUpdate(Ptr<Level_New>& level) {
		
	}

	void GameLoop::HalfFrameRateUpdate(Ptr<Level_New>& level) {

	}

	void GameLoop::SecondUpdate(Ptr<Level_New>& level) {
		static std::chrono::time_point begin{ std::chrono::high_resolution_clock::now() };
		static std::chrono::time_point end{ std::chrono::high_resolution_clock::now() };
		begin = std::chrono::high_resolution_clock::now();

		LOG("Second: " + (long long)std::chrono::duration_cast<std::chrono::seconds>(end - begin));

		end = std::chrono::high_resolution_clock::now();

	}

	void GameLoop::HalfSecondUpdate(Ptr<Level_New>& level) {

	}
}