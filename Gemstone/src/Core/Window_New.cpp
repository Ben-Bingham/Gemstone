#include "pch.h"
#include "Window_New.h"

#include <GLFW/glfw3.h>

namespace Gem {
<<<<<<< HEAD
	Window_New::Window_New() {
=======
	Window::Window() {
>>>>>>> c45902e481ceeaa56edb35b99852a647fa53ac3e
		glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);

		m_Handle = glfwCreateWindow(size.x, size.y, "Gemstone", nullptr, nullptr);

		if (!m_Handle) {
			LOG("Failed to create Window.", LogLevel::TERMINAL);
		}
	}

<<<<<<< HEAD
	Window_New::~Window_New() {
		glfwDestroyWindow(m_Handle);
	}

	void Window_New::SwapBuffers() {
=======
	Window::~Window() {
		glfwDestroyWindow(m_Handle);
	}

	void Window::SwapBuffers() {
>>>>>>> c45902e481ceeaa56edb35b99852a647fa53ac3e
		glfwSwapBuffers(m_Handle);
	}


}