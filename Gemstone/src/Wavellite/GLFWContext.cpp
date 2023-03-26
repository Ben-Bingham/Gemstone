#include "GLFWContext.h"

#include <GLFW/glfw3.h>

#include "Lazuli/Log.h"

namespace Wavellite {
	void GLFWContext::StartUp() {
		glfwSetErrorCallback(ErrorCallback);

		if (!glfwInit()) {
			LOG("GLFW failed to init", Lazuli::LogLevel::TERMINAL);
		}
	}

	void GLFWContext::ShutDown() {
		glfwTerminate();
	}

	void ErrorCallback(const int error, const char* description) {
		LOG("GLFW error: " + std::to_string(error) + std::string(description), Lazuli::LogLevel::ERROR);
	}
}


