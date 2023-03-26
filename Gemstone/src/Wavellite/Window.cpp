#include "Window.h"

#include "Input/IOManager.h"
#include "Lazuli/Log.h"
#include "Celestite/Pointer.h"

namespace Wavellite {
	Window::Window() {
		m_Handle = glfwCreateWindow(200, 100, "Window", nullptr, nullptr);
		
		if (!m_Handle) {
			LOG("Window failed to be created", Lazuli::LogLevel::TERMINAL);
		}

        glfwMakeContextCurrent(m_Handle);
        if (glewInit() != GLEW_OK) { // TODO maybe make this its own class, it could also manage OpengGl state.
			LOG("GLEW failed to be initialized", Lazuli::LogLevel::TERMINAL);
        }
	}

	bool Window::IsOpen() const {
		return !glfwWindowShouldClose(m_Handle);
	}

	void Window::Close() const {
		glfwSetWindowShouldClose(m_Handle, true);
	}

	Window& Window::Get() {
		static Window window;
		return window;
	}
//
// 	void Window::Init() {
// 		if (m_Initialized) {
// 			return;
// 		}
//
// 		if (!glfwInit()) {
// 			LOG("GLFW failed to initialize.", Lazuli::LogLevel::TERMINAL);
// 		}
//
// #ifdef WAVELLITE_DEBUG
// 		glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);
// #endif // RUBY_DEBUG
//
// 		m_Window = glfwCreateWindow(m_Width, m_Height, "Gemstone", nullptr, nullptr);
//
// 		glfwMakeContextCurrent(m_Window);
//
// 		m_ProjectionMatrix = Malachite::perspective(45.0f, (float)m_Width / (float)m_Height, 0.1f, 100.0f);
//
// 		glfwSetWindowUserPointer(m_Window, new IOManager{});
// 	}
//
// 	void Window::setDimensions(unsigned int width, unsigned int height) {
// 		m_Width = width;
// 		m_Height = height;
//
// 		m_ProjectionMatrix = Malachite::perspective(45.0f, (float)((float)m_Width / (float)m_Height), 0.1f, 100.0f); //TODO renderer never knows to reupload projection matrix
//
// 		glViewport(0, 0, m_Width, m_Height);
// 	}
//
// 	void windowSizeCallBack(GLFWwindow* window, int width, int height) {
// 		Window::Get().setDimensions((unsigned int)width, (unsigned int)height);
// 	}
}