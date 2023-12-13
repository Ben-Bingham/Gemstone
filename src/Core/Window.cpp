#include <GLFW/glfw3.h>
#include "Utility/Log.h"
#include "Core/Window.h"

namespace Gem {
	void Window::StartUp() {
		glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);

		m_Handle = glfwCreateWindow(size.x, size.y, "Gemstone", nullptr, nullptr);

		if (!m_Handle) {
			LOG("Failed to create Window.", LogLevel::TERMINAL);
		}
	}

	void Window::ShutDown() {
		glfwDestroyWindow(m_Handle);
	}

	void Window::SwapBuffers() {
		glfwSwapBuffers(m_Handle);
	}
}