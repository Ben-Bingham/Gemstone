#include "pch.h"
#include "Time/Time.h"

#include <GLFW/glfw3.h>

namespace Gem {
	float Time::GetTime() {
		return (float)glfwGetTime();
	}

	void Time::Wait(const float seconds) {
		float endTime = GetTime() + seconds;

		while (GetTime() < endTime) { }


// 		const float requiredTimeDifference = 1.0f / (float)Settings::maxFPS;
// 		float timeDifference;
// 		do {
// 			timeDifference = Time::GetTime() - frameStart;
//
// #ifdef GEMSTONE_DEBUG
// 			if (timeDifference > 5 * requiredTimeDifference) {
// 				LOG("Frame took more than five times standard time, Breakpoint assumed.", Lazuli::LogLevel::WARNING);
// 				timeDifference = requiredTimeDifference;
// 			}
// #endif
// 		} while (timeDifference < requiredTimeDifference);
	}
}