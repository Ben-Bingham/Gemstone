#include "pch.h"
#include "Application.h"
#include "Level.h"
#include "New Rendering/Renderer.h"
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

		// g_Engine.imGuiContext.StartUiFrame();

		g_Engine.humanInterfaceDeviceContext.PollEvents();
		g_Engine.eventManager.Distribute();

		level->Step();

		g_Engine.renderer.Render(/*level->renderables TODO*/);

		Time::Wait(endTime - Time::GetTime());
	}
}