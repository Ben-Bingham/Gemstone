#include "Core/Game.h"
#include "Core/Settings.h"
#include "Core/Window.h"
#include "Core/Event System/EventSystem.h"

#include "Rendering/Renderer_New.h"

#include "Utility/Utility.h"

namespace Gem {
	void Game::Run(Ptr<Level> level, ConditionFunction conditionFunction) {
		float dt = 1.0f / (float)Settings::Get().GetMaxFramerate();
		while (conditionFunction(level) == true && !Window::Get().ShouldClose()) {
			const float frameStartTime = m_TimeManager.GetTime();

			GLFWContext::Get().PollEvents();
			EventSystem::Get().Distribute();

			// ==================== Game Loop ====================
			Print(dt * 1000.0f);

			level->ecs.systemManager.Step();


			// Physicist.Step();

			Renderer_New::Get().Render();
			// DebugRenderer.Render();
			// Ui.Render();

			// ==================== Game Loop ====================

			 Window::Get().SwapBuffers();

			dt = DelayFrame(frameStartTime);
		}
	}

	float Game::DelayFrame(float frameStartTime) const {
		if (!Settings::Get().GetVSync()) {
			const float dt = 1.0f / (float)Settings::Get().GetMaxFramerate();

			const float waitTime = std::ceil((m_TimeManager.GetTime() - frameStartTime) / dt) * dt;

			m_TimeManager.Wait(waitTime);
		}

		return m_TimeManager.GetTime() - frameStartTime;
	}
}