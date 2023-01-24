#include "Window.h"

#include "Input/IOManager.h"
#include "Log.h"
#include "Pointer.h"

namespace Wavellite {
	Window& Window::Get() {
		static Window window;
		return window;
	}

	void Window::Init() {
		if (m_Initialized) {
			return;
		}

		if (!glfwInit()) {
			LOG("GLFW failed to initialize.", Lazuli::LogLevel::TERMINAL);
		}

#ifdef WAVELLITE_DEBUG
		glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);
#endif // RUBY_DEBUG

		m_Window = glfwCreateWindow(m_Width, m_Height, "Gemstone", nullptr, nullptr);

		glfwMakeContextCurrent(m_Window);

		m_ProjectionMatrix = Malachite::perspective(45.0f, (float)m_Width / (float)m_Height, 0.1f, 100.0f);

		glfwSetWindowUserPointer(m_Window, new IOManager{});
	}

	void Window::setDimensions(unsigned int width, unsigned int height) {
		m_Width = width;
		m_Height = height;

		m_ProjectionMatrix = Malachite::perspective(45.0f, (float)((float)m_Width / (float)m_Height), 0.1f, 100.0f); //TODO renderer never knows to reupload projection matrix

		glViewport(0, 0, m_Width, m_Height);
	}

	void windowSizeCallBack(GLFWwindow* window, int width, int height) {
		Window::Get().setDimensions((unsigned int)width, (unsigned int)height);
	}
}