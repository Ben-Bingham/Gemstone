#include "Window.h"

#include "Log.h"

namespace Ruby {
	Window::Window(unsigned int width, unsigned int height, std::string name) {
		glfwInit();

		m_Window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);

		glfwMakeContextCurrent(m_Window);
		glfwSwapInterval(1);
	}

	void Window::dispose() {
		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}
}