#include "pch.h"
#include "Application.h"
#include "Level.h"
#include "Rendering/Renderer.h"
#include "Utility/Time.h"

namespace Gem {
	void Application::Load(const Ptr<Level>& level) const {
		level->InternalLoad();

		while (g_Engine.window.IsOpen() && level->IsRunning()) {
			ExecuteFrame(level);
		}

		level->InternalUnload();
	}

	void Application::ExecuteFrame(const Ptr<Level>& level) const {
		const float endTime = Time::GetTime() + 1.0f / static_cast<float>(Settings::maxFPS);

		const float deltaTime = endTime - m_LastEndTime;

		g_Engine.imGuiContext.StartUiFrame();

		g_Engine.humanInterfaceDeviceContext.PollEvents();
		g_Engine.eventManager.Distribute();

		level->Step(deltaTime);

		g_Engine.renderer.Render();

		Time::Wait(endTime - Time::GetTime()); // TODO dosent factor in frame taking too long
	}
}