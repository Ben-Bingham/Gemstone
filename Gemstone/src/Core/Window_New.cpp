#include "pch.h"
#include "Window_New.h"

#include <GLFW/glfw3.h>

namespace Gem {
	Window_New::Window_New() {
		glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);

		m_Handle = glfwCreateWindow(size.x, size.y, "Gemstone", nullptr, nullptr);

		if (!m_Handle) {
			LOG("Failed to create Window.", LogLevel::TERMINAL);
		}
	}

	Window_New::~Window_New() {
		glfwDestroyWindow(m_Handle);
	}

	void Window_New::SwapBuffers() {
		glfwSwapBuffers(m_Handle);
	}


}