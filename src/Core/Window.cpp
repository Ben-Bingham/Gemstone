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
		GLFWContext::Get().DestroyWindow(Get().m_Handle);

		m_Started = false;
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

	void Window::DisableCursor() {
		GLFWContext::Get().DisableCursor(m_Handle);
	}

	void Window::EnableCursor() {
		GLFWContext::Get().EnableCursor(m_Handle);
	}

	// ==================== Input ====================
	bool Window::GetMouseButton(const MouseButton button) {
		return GLFWContext::Get().GetMouseButtonDown(m_Handle, button);
	}

	Vector2i Window::GetMousePosition() {
		return GLFWContext::Get().GetMousePosition(m_Handle);
	}

	bool Window::GetKeyboardKey(const Key key) {
		return GLFWContext::Get().GetKeyDown(m_Handle, key);
	}

	void Window::SetKeyboardKeyCallback(void(* callback)(WindowHandle callbackHandle, int key, int scanCode, int action, int mods)) {
		GLFWContext::Get().SetKeyboardKeyCallback(m_Handle, callback);
	}

	void Window::SetMouseButtonCallback(void(* callback)(WindowHandle callbackHandle, int button, int action, int mods)) {
		GLFWContext::Get().SetMouseButtonCallback(m_Handle, callback);
	}

	void Window::SetMousePositionCallback(void(* callback)(WindowHandle callbackHandle, double xPos, double yPos)) {
		GLFWContext::Get().SetMousePositionCallback(m_Handle, callback);
	}

	void Window::SetScrollWheelCallback(void(* callback)(WindowHandle callbackHandle, double xOffset, double yOffset)) {
		GLFWContext::Get().SetScrollWheelCallback(m_Handle, callback);
	}

	void Window::SetCursorEnterCallback(void(* callback)(WindowHandle callbackHandle, int entered)) {
		GLFWContext::Get().SetCursorEnterCallback(m_Handle, callback);
	}

	void Window::SetWindowResizeCallback(void(* callback)(WindowHandle callbackHandle, int width, int height)) {
		GLFWContext::Get().SetWindowResizeCallback(m_Handle, callback);
	}
}