#pragma once

namespace Wavellite {
	class Time {
	public:
		Time() {
			previousTime = (float)glfwGetTime();
		}

		void endFrame() {
			float currentTime = (float)glfwGetTime();
			deltaTime = currentTime - previousTime;
		}

		float deltaTime;

	private:
		float previousTime;
	};
}