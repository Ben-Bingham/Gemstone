#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Gem {
	class Time { //TODO make singleton
	public:
		// Time() {
		// 	previousTime = (float)glfwGetTime();
		// }
		//
		// void endFrame() {
		// 	float currentTime = (float)glfwGetTime();
		// 	deltaTime = currentTime - previousTime;
		// 	previousTime = (float)glfwGetTime();
		// 	frameCount++;
		// }
		//
		// float getTime() {
		// 	return (float)glfwGetTime();
		// }
		//
		// float deltaTime{ 0.0f };
		// unsigned int frameCount{ 0u };

		float GetTime() {
			return (float)glfwGetTime();
		}

	private:
		// float previousTime;
	};
}