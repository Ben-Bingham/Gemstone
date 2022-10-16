#pragma once

#include <GLFW/glfw3.h>

namespace Wavellite {
	class Time {
	public:
		Time() {
			previousTime = (float)glfwGetTime();
		}

		void endFrame() {
			float currentTime = (float)glfwGetTime();
			deltaTime = currentTime - previousTime;
			previousTime = (float)glfwGetTime();
		}

		float deltaTime{ 0.0f };

	private:
		float previousTime;
	};
}