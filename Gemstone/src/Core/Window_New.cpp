#include "pch.h"
#include "Window_New.h"

#include <GLFW/glfw3.h>

namespace Gem {
	Window::Window() {
		glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);

		m_Handle = glfwCreateWindow(size.x, size.y, "Gemstone", nullptr, nullptr);

		if (!m_Handle) {
			LOG("Failed to create Window.", LogLevel::TERMINAL);
		}
	}

	Window::~Window() {
		glfwDestroyWindow(m_Handle);
	}

	void Window::SwapBuffers() {
		glfwSwapBuffers(m_Handle);
	}


}