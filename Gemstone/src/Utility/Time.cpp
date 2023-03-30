#include "pch.h"

#include <GLFW/glfw3.h>

#include "Utility/Time.h"

namespace Gem::Time {
	float GetTime() {
		return (float)glfwGetTime();
	}

	void Wait(const float seconds) {
		const float endTime = GetTime() + seconds;

		while (GetTime() < endTime) { }
	}
}