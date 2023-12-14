#include "Core/Game.h"
#include "Core/Engine.h"
#include "Utility/Utility.h"

namespace Gem {
	Game::Game(Engine& engine) 
		: engine(engine), m_TimeManager(engine.glfwContext) { }

	void Game::Run(Ptr<Level> level, ConditionFunction conditionFunction) {
		float dt = 1.0f / (float)engine.settings.GetMaxFramerate();
		while (conditionFunction(level) == true && !engine.window.ShouldClose()) {
			const float frameStartTime = m_TimeManager.GetTime();

			engine.glfwContext.PollEvents();
			engine.eventSystem.Distribute();

			Print(dt * 1000.0f);

			engine.window.SwapBuffers();

			dt = DelayFrame(frameStartTime);
		}
	}

	float Game::DelayFrame(float frameStartTime) const {
		if (!engine.settings.GetVSync()) {
			const float dt = 1.0f / (float)engine.settings.GetMaxFramerate();

			const float waitTime = std::ceil((m_TimeManager.GetTime() - frameStartTime) / dt) * dt;

			m_TimeManager.Wait(waitTime);
		}

		return m_TimeManager.GetTime() - frameStartTime;
	}
}