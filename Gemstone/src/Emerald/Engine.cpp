#include "pch.h"
#include "Engine.h"

#include "Settings.h"

#include "Time/Time.h"

namespace Gem {
	Engine::Engine() {
		humanInterfaceDeviceContext.StartUp();
	}

	void Engine::ExecuteFrame(const Celestite::Ptr<Level>& level) const {
		const float endTime = Time::GetTime() + 1.0f / (float)Settings::maxFPS;

		humanInterfaceDeviceContext.PollEvents();

		level->Step();

		// Ruby::Renderer::Render();

		Time::Wait(endTime - Time::GetTime());
	}

	Engine::~Engine() {
		humanInterfaceDeviceContext.ShutDown();
	}
}