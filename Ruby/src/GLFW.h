#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Log.h"

namespace Ruby {
	class GLFW {
	public:
		GLFW() {}

		void start() {
			if (!glfwInit()) {
				LOG("GLFW failed to initialize.", Lazuli::LogLevel::TERMINAL);
			}
		}

		void stop() {
			glfwTerminate();
		}
	};
}