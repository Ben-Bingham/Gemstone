#include <GLFW/glfw3.h>

#include "Core/GLFWContext.h"

#include "Utility/Log.h"

namespace Gem {
	void GLFWErrorCallback(int error, const char* description) {
		LOG("GLFW error: " + std::to_string(error) + " " + std::string(description), LogLevel::ERROR);
	}

	void GLFWContext::StartUp() {
		m_Started = true;

		glfwSetErrorCallback(GLFWErrorCallback);

		if (!glfwInit()) {
			LOG("GLFW failed to init", LogLevel::TERMINAL);
		}
	}

	void GLFWContext::ShutDown() {
		glfwTerminate();

		m_Started = false;
	}

	GLFWContext& GLFWContext::Get() {
		if (!m_Started) {
			LOG("Failed to StartUp GLFWContext, before using it.", LogLevel::TERMINAL);
		}

		static GLFWContext glfwContext;
		return glfwContext;
	}

	// ==================== Windows ====================
	WindowHandle GLFWContext::CreateWindow(const Vector2ui size, std::string&& name) {
		return glfwCreateWindow((int)size.x, (int)size.y, name.c_str(), nullptr, nullptr);
	}

	void GLFWContext::DestroyWindow(WindowHandle handle) {
		glfwDestroyWindow(handle);
	}

	bool GLFWContext::WindowShouldClose(WindowHandle handle) {
		return glfwWindowShouldClose(handle);
	}

	void GLFWContext::SetWindowHint(WindowHint hint, const bool value) {
		glfwWindowHint((int)hint, value);
	}

	// ==================== Cursor ====================
	void GLFWContext::EnableCursor(WindowHandle handle) {
		glfwSetInputMode(handle, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	}

	void GLFWContext::DisableCursor(WindowHandle handle) {
		glfwSetInputMode(handle, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	}

	// ==================== Input ====================
	void GLFWContext::PollEvents() const {
		glfwPollEvents();
	}

	bool GLFWContext::GetKeyDown(const WindowHandle handle, const Key key) const {
		return glfwGetKey(handle, (int)key) == GLFW_PRESS;
	}

	bool GLFWContext::GetKeyUp(const WindowHandle handle, const Key key) const {
		return glfwGetKey(handle, (int)key) == GLFW_RELEASE;
	}

	bool GLFWContext::GetMouseButtonDown(const WindowHandle handle, const MouseButton button) const {
		return glfwGetMouseButton(handle, (int)button) == GLFW_PRESS;
	}

	bool GLFWContext::GetMouseButtonUp(WindowHandle handle, MouseButton button) const {
		return glfwGetMouseButton(handle, (int)button) == GLFW_RELEASE;
	}

	Vector2i GLFWContext::GetMousePosition(const WindowHandle handle) const {
		double x, y;

		glfwGetCursorPos(handle, &x, &y);

		return Vector2i{ (int)std::floor(x), (int)std::floor(y) };
	}

	// ==================== Call backs ====================
	void GLFWContext::SetKeyboardKeyCallback(const WindowHandle handle, void(* callback)(WindowHandle callbackHandle, int key, int scanCode, int action, int mods)) {
		if (m_KeyCallback) {
			LOG("Overwritting the value of keyboard key callback", LogLevel::ERROR);
		}

		glfwSetKeyCallback(handle, callback);
		m_KeyCallback = true;
	}

	void GLFWContext::SetMouseButtonCallback(const WindowHandle handle, void(* callback)(WindowHandle callbackHandle, int button, int action, int mods)) {
		if (m_MouseButtonCallback) {
			LOG("Overwritting the value of mouse button callback", LogLevel::ERROR);
		}

		glfwSetMouseButtonCallback(handle, callback);
		m_MouseButtonCallback = true;
	}

	void GLFWContext::SetMousePositionCallback(const WindowHandle handle, void(* callback)(WindowHandle callbackHandle, double xPos, double yPos)) {
		if (m_MousePositionCallback) {
			LOG("Overwritting the value of mouse position callback", LogLevel::ERROR);
		}

		glfwSetCursorPosCallback(handle, callback);
		m_MousePositionCallback = true;
	}

	void GLFWContext::SetScrollWheelCallback(const WindowHandle handle, void(* callback)(WindowHandle callbackHandle, double xOffset, double yOffset)) {
		if (m_ScrollWheelCallback) {
			LOG("Overwritting the value of mouse scroll wheel callback", LogLevel::ERROR);
		}

		glfwSetScrollCallback(handle, callback);
		m_ScrollWheelCallback = true;
	}

	void GLFWContext::SetCursorEnterCallback(const WindowHandle handle, void(* callback)(WindowHandle callbackHandle, int entered)) {
		if (m_CursorEnterCallback) {
			LOG("Overwritting the value of cursor enter callback", LogLevel::ERROR);
		}

		glfwSetCursorEnterCallback(handle, callback);
		m_CursorEnterCallback = true;
	}

	void GLFWContext::SetWindowResizeCallback(const WindowHandle handle, void(* callback)(WindowHandle callbackHandle, int width, int height)) {
		if (m_WindowResizeCallback) {
			LOG("Overwritting the value of kwindow resize callback", LogLevel::ERROR);
		}

		glfwSetWindowSizeCallback(handle, callback);
		m_WindowResizeCallback = true;
	}

	// ==================== Miscellaneous ====================
	double GLFWContext::GetElapsedTime() {
		return glfwGetTime();
	}

	void GLFWContext::MakeOpenGlContextCurrent(WindowHandle handle) {
		glfwMakeContextCurrent(handle);
	}

	// ==================== Buffers ====================
	void GLFWContext::SwapBuffers(WindowHandle handle) const {
		glfwSwapBuffers(handle);
	}

	void GLFWContext::SwapInterval(const int interval) {
		glfwSwapInterval(interval);
	}
}