#include <GLFW/glfw3.h>

#include "Utility/Log.h"
#include "Core/Window.h"

namespace Gem {
	void Window::StartUp() {
		m_Started = true;

		GLFWContext::Get().SetWindowHint(GLFWContext::WindowHint::OPENGL_DEBUG_CONTEXT, true);

		Get().m_Handle = GLFWContext::Get().CreateWindow(Get().size, "Gemstone");

		if (!Get().m_Handle) {
			LOG("Failed to create Window.", LogLevel::TERMINAL);
		}

		GLFWContext::Get().MakeOpenGlContextCurrent(Get().m_Handle);
	}

	void Window::ShutDown() {
		m_Started = false;
		GLFWContext::Get().DestroyWindow(Get().m_Handle);
	}

	Window& Window::Get() {
		if (!m_Started) {
			LOG("Failed to StartUp Window, before using it.", LogLevel::TERMINAL);
		}

		static Window window;
		return window;
	}

	void Window::SwapBuffers() {
		GLFWContext::Get().SwapBuffers(m_Handle);
	}

	void Window::SwapInterval(int interval) {
		GLFWContext::Get().SwapInterval(interval);
	}

	bool Window::ShouldClose() {
		return GLFWContext::Get().WindowShouldClose(m_Handle);
	}
}