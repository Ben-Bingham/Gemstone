#include "pch.h"
#include "Application.h"
#include "Level.h"
#include "Rendering/Renderer.h"

namespace Gem {
	void Application::Load(const Ptr<Level>& level) const {
		level->InternalLoad();

		while (g_Engine.window.IsOpen() && level->IsRunning()) {
			ExecuteFrame(level);
		}

		level->InternalUnload();
	}

	void Application::ExecuteFrame(const Ptr<Level>& level) const {
		const float endTime = g_Engine.humanInterfaceDeviceContext.GetTime() + 1.0f / static_cast<float>(Settings::maxFPS);

		const float deltaTime = endTime - m_LastEndTime;

		g_Engine.imGuiContext.StartUiFrame();

		g_Engine.humanInterfaceDeviceContext.PollEvents();
		g_Engine.eventManager.Distribute();

		level->Step(deltaTime);

		{ // Rendering
			g_Engine.renderer.RenderSetup();

			g_Engine.renderer.Render();
			g_Engine.imGuiContext.RenderUi();

			g_Engine.renderer.RenderCleanup();
		}

		g_Engine.humanInterfaceDeviceContext.Wait(endTime - g_Engine.humanInterfaceDeviceContext.GetTime());
		m_LastEndTime = endTime;
	}
}