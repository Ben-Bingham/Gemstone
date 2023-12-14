#include <GLFW/glfw3.h>

#include "Core/GLFWContext.h"

#include "Utility/Log.h"

namespace Gem {
	void GLFWErrorCallback(int error, const char* description) {
		LOG("GLFW error: " + std::to_string(error) + " " + std::string(description), LogLevel::ERROR);
	}

	void GLFWContext::StartUp() {
		glfwSetErrorCallback(GLFWErrorCallback);

		if (!glfwInit()) {
			LOG("GLFW failed to init", LogLevel::TERMINAL);
		}
	}

	void GLFWContext::ShutDown() {
		glfwTerminate();
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

	// ==================== Miscellaneous ====================
	double GLFWContext::GetElapsedTime() {
		return glfwGetTime();
	}

	void GLFWContext::PollEvents() const {
		glfwPollEvents();
	}

	// ==================== Buffers ====================
	void GLFWContext::SwapBuffers(WindowHandle handle) const {
		glfwSwapBuffers(handle);
	}

	void GLFWContext::SwapInterval(const int interval) {
		glfwSwapInterval(interval);
	}
}