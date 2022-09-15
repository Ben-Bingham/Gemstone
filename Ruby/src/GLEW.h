#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Log.h"

namespace Ruby {
	class GLEW {
	public:
		GLEW() {}

		void start() {
			if (glewInit() != GLEW_OK) {
				LOG("GLEW failed to initialize.", Lazuli::LogLevel::TERMINAL);
			}
		}
	};
}