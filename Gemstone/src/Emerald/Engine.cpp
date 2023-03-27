#include "pch.h"
#include "Engine.h"

#include "Settings.h"

#include "Time/Time.h"
#include "Lazuli/Log.h"

namespace Gem {
	Engine::Engine() {
		glfwContext.StartUp();
	}

	void Engine::ExecuteFrame(const Celestite::Ptr<Level>& scene) const {
		const float frameStart = Time::GetTime();

		glfwContext.PollEvents();

		scene->Step();

		// Ruby::Renderer::Render();

		const float requiredTimeDifference = 1.0f / (float)Settings::maxFPS;
		float timeDifference;
		do {
			timeDifference = Time::GetTime() - frameStart;

#ifdef GEMSTONE_DEBUG
			if (timeDifference > 5 * requiredTimeDifference) {
				LOG("Frame took more than five times standard time, Breakpoint assumed.", Lazuli::LogLevel::WARNING);
				timeDifference = requiredTimeDifference;
			}
#endif
		}
		while (timeDifference < requiredTimeDifference);
	}

	Engine::~Engine() {
		glfwContext.ShutDown();
	}
}