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
			frameCount++;
		}

		float getTime() {
			return (float)glfwGetTime();
		}

		float deltaTime{ 0.0f };
		unsigned int frameCount{ 0u };

	private:
		float previousTime;
	};
}