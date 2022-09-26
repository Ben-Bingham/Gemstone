#include "Window.h"

#include "Log.h"

namespace Ruby {
	Window::Window(unsigned int width, unsigned int height, std::string name) 
		: m_ProjectionMatrix{Malachite::perspective(45.0f, (float)((float)width / (float)height), 0.1f, 100.0f)}
		, m_Width(width)
		, m_Height(height) {
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

		glfwSetWindowUserPointer(m_Window, (void*)&ioManger);

		// Mouse
		setMousePositionCallback(mousePositionCallback);
		setMouseButtonCallback(mouseButtonCallback);
		setScrollWheelCallback(mouseScrolWheelCallback);
		setCursorEntersCallback(cursorEnterCallback);

		// Keyboard
		setKeyCallback(keyCallback);
	}
}