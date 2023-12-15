#include <GLFW/glfw3.h>
#include "Utility/Log.h"
#include "Core/Window.h"

namespace Gem {
	Window::Window(GLFWContext& glfwContext)
		: m_Context(glfwContext) {}

	void Window::StartUp() {
		m_Context.SetWindowHint(GLFWContext::WindowHint::OPENGL_DEBUG_CONTEXT, true);

		m_Handle = m_Context.CreateWindow(size, "Gemstone");

		if (!m_Handle) {
			LOG("Failed to create Window.", LogLevel::TERMINAL);
		}

		m_Context.MakeOpenGlContextCurrent(m_Handle);
	}

	void Window::ShutDown() {
		m_Context.DestroyWindow(m_Handle);
	}

	void Window::SwapBuffers() {
		m_Context.SwapBuffers(m_Handle);
	}

	void Window::SwapInterval(int interval) {
		m_Context.SwapInterval(interval);
	}

	bool Window::ShouldClose() {
		return m_Context.WindowShouldClose(m_Handle);
	}
}