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

		constexpr float frameTime = 1.0f / (float)fps;
		constexpr float halfFrameTime = frameTime / 2;


		while (level->running) {
			const float loopStartTime = (float)m_Engine.glfwContext.time.GetElapsedTime();

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
				float frameTimeSoFar = (float)m_Engine.glfwContext.time.GetElapsedTime() - loopStartTime;

				if (frameTimeSoFar > halfFrameTime) {
					frameTimeSoFar -= std::floor(frameTimeSoFar / halfFrameTime);
				}

				m_Engine.glfwContext.time.Wait(halfFrameTime - frameTimeSoFar);
			}
			else {
				if (EqualEnough((float)m_Engine.glfwContext.time.GetElapsedTime() / 0.5f, (float)m_HalfSecondCounter, 0.6f)) {
					m_HalfSecondCounter++;
					HalfSecondUpdate(level);

					if (m_HalfSecondCounter % 2 == 0) {
						SecondUpdate(level);
					}
				} 
			}
		}
	}

	void GameLoop::SetWindow(Window_New* window) {
		m_Window = window;
	}

	void GameLoop::DoubleFrameRateUpdate(Ptr<Level_New>& level) {
		static float begin{ (float)m_Engine.glfwContext.time.GetElapsedTime() };
		static float end{ (float)m_Engine.glfwContext.time.GetElapsedTime() };
		end = (float)m_Engine.glfwContext.time.GetElapsedTime();

		LOG("Double Frame rate: " + std::to_string(end - begin));

		begin = (float)m_Engine.glfwContext.time.GetElapsedTime();
	}

	void GameLoop::FrameRateUpdate(Ptr<Level_New>& level) {
<<<<<<< HEAD
		GLFWContext::Time::ScopeProfiler scope{ m_Engine.glfwContext.time };
//#ifdef GEMSTONE_DEBUG
//		if (!m_Window) {
//			LOG("Window became null.", LogLevel::TERMINAL);
//		}
//#endif
//
//		m_Engine.eventSystem.Distribute();
//		LOG("Runnings");
//		m_Window->SwapBuffers();
//
//		m_Engine.glfwContext.PollEvents();
=======

>>>>>>> c45902e481ceeaa56edb35b99852a647fa53ac3e
	}

	void GameLoop::HalfFrameRateUpdate(Ptr<Level_New>& level) {

	}

	void GameLoop::SecondUpdate(Ptr<Level_New>& level) {
<<<<<<< HEAD
=======
		static float begin{ (float)m_Engine.glfwContext.time.GetElapsedTime() };
		static float end{ (float)m_Engine.glfwContext.time.GetElapsedTime() };
		end = (float)m_Engine.glfwContext.time.GetElapsedTime();

		LOG("Second: " + std::to_string(end - begin));
>>>>>>> c45902e481ceeaa56edb35b99852a647fa53ac3e

		begin = (float)m_Engine.glfwContext.time.GetElapsedTime();
	}

	void GameLoop::HalfSecondUpdate(Ptr<Level_New>& level) {

	}
}