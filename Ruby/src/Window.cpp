#include "Window.h"

#include "Log.h"

namespace Ruby {
	Window::Window(unsigned int width, unsigned int height, std::string name) {
		if (!glfwInit()) {
			LOG("GLFW failed to initialize.", Lazuli::LogLevel::TERMINAL);
		}

		m_Window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);

		if (!m_Window) {
			LOG("Window could not be initialized.", Lazuli::LogLevel::TERMINAL);
		}

		glfwMakeContextCurrent(m_Window);

		if (glewInit() != GLEW_OK) {
			LOG("GLEW failed to initialize.", Lazuli::LogLevel::TERMINAL);
		}

		glfwSwapInterval(1);
	}

	void Window::dispose() {
		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}
}