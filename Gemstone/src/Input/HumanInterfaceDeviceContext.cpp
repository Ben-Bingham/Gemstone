#include "pch.h"

#include <GLFW/glfw3.h>

#include "HumanInterfaceDeviceContext.h"
#include "Math/Vector.h"
#include "Utility/Log.h"

namespace Gem {
	void ErrorCallback(const int error, const char* description) {
		LOG("GLFW error: " + std::to_string(error) + " " + std::string(description), LogLevel::ERROR);
	}

	void HumanInterfaceDeviceContext::StartUp() {
		glfwSetErrorCallback(ErrorCallback);

		if (!glfwInit()) {
			LOG("GLFW failed to init", LogLevel::TERMINAL);
		}
	}

	void HumanInterfaceDeviceContext::ShutDown() {
		glfwTerminate();
	}

	void HumanInterfaceDeviceContext::PollEvents() const {
		glfwPollEvents();
	}

	WindowHandle HumanInterfaceDeviceContext::CreateWindowHandle(const Vector2ui& size, const std::string& title) const {
		glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

		const WindowHandle handle = glfwCreateWindow(size.x, size.y, title.c_str(), nullptr, nullptr);
		if (!handle) {
			LOG("Failed to create Window Handle.", LogLevel::TERMINAL);
		}

		glfwSetWindowUserPointer(handle, (void*)&m_UserWindowData);

		return handle;
	}

	void HumanInterfaceDeviceContext::MakeGraphicsContextCurrent(WindowHandle handle) {
		glfwMakeContextCurrent(handle);
	}

	void HumanInterfaceDeviceContext::CloseWindow(WindowHandle handle) {
		glfwSetWindowShouldClose(handle, true);
	}

	bool HumanInterfaceDeviceContext::ShouldWindowClose(WindowHandle handle) {
		return glfwWindowShouldClose(handle);
	}

	void HumanInterfaceDeviceContext::SwapBuffers(WindowHandle handle) {
		glfwSwapBuffers(handle);
	}

	void HumanInterfaceDeviceContext::SetSwapInterval(const size_t interval) {
		glfwSwapInterval((int)interval);
	}

	bool HumanInterfaceDeviceContext::GetKey(const WindowHandle handle, Key key) const {
		return glfwGetKey(handle, (int)key) == GLFW_PRESS;
	}

	bool HumanInterfaceDeviceContext::GetMouseButton(const WindowHandle handle, MouseButton button) const {
		return glfwGetMouseButton(handle, (int)button) == GLFW_PRESS;
	}

	Vector2i HumanInterfaceDeviceContext::GetMousePosition(const WindowHandle handle) const {
		double x, y;
		
		glfwGetCursorPos(handle, &x, &y);

		return Vector2i{ (int)std::floor(x), (int)std::floor(y) };
	}

	void HumanInterfaceDeviceContext::DisableCursor(const WindowHandle handle) {
		glfwSetInputMode(handle, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	}

	void HumanInterfaceDeviceContext::EnableCursor(WindowHandle handle) {
		glfwSetInputMode(handle, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	}

	// Callbacks
	void HumanInterfaceDeviceContext::SetKeyCallback(const WindowHandle handle, void(*callback)(WindowHandle callbackHandle, int key, int scanCode, int action, int mods)) {
#ifdef GEMSTONE_DEBUG
		if (m_KeyCallbackInitialized) {
			LOG("Key callback already initialized", LogLevel::ERROR);
			return;
		}
#endif

		glfwSetKeyCallback(handle, callback);
#ifdef GEMSTONE_DEBUG
		m_KeyCallbackInitialized = true;
#endif
	}

	void HumanInterfaceDeviceContext::SetMouseButtonCallback(const WindowHandle handle, void(* callback)(WindowHandle callbackHandle, int button, int action, int mods)) {
#ifdef GEMSTONE_DEBUG
		if (m_MouseButtonCallbackInitialized) {
			LOG("Mouse button callback already initialized", LogLevel::ERROR);
			return;
		}
#endif
		glfwSetMouseButtonCallback(handle, callback);
#ifdef GEMSTONE_DEBUG
		m_MouseButtonCallbackInitialized = true;
#endif
	}

	void HumanInterfaceDeviceContext::SetMousePositionCallback(const WindowHandle handle, void(* callback)(WindowHandle callbackHandle, double xPos, double yPos)) {
#ifdef GEMSTONE_DEBUG
		if (m_MousePositionCallbackInitialized) {
			LOG("Mouse position callback already initialized", LogLevel::ERROR);
			return;
		}
#endif
		glfwSetCursorPosCallback(handle, callback);
#ifdef GEMSTONE_DEBUG
		m_MousePositionCallbackInitialized = true;
#endif
	}

	void HumanInterfaceDeviceContext::SetScrollCallback(const WindowHandle handle, void(* callback)(WindowHandle callbackHandle, double xOffset, double yOffset)) {
#ifdef GEMSTONE_DEBUG
		if (m_ScrollCallbackInitialized) {
			LOG("Scroll callback already initialized", LogLevel::ERROR);
			return;
		}
#endif
		glfwSetScrollCallback(handle, callback);
#ifdef GEMSTONE_DEBUG
		m_ScrollCallbackInitialized = true;
#endif
	}

	void HumanInterfaceDeviceContext::SetCursorEnterCallback(const WindowHandle handle, void(* callback)(WindowHandle callbackHandle, int entered)) {
#ifdef GEMSTONE_DEBUG
		if (m_CursorEnterCallbackInitialized) {
			LOG("Cursor enter callback already initialized", LogLevel::ERROR);
			return;
		}
#endif
		glfwSetCursorEnterCallback(handle, callback);
#ifdef GEMSTONE_DEBUG
		m_CursorEnterCallbackInitialized = true;
#endif
	}

	void HumanInterfaceDeviceContext::SetWindowSizeCallback(const WindowHandle handle, void(* callback)(WindowHandle callbackHandle, int width, int height)) {
#ifdef GEMSTONE_DEBUG
		if (m_WindowSizeCallbackInitialized) {
			LOG("Window size callback already initialized", LogLevel::ERROR);
			return;
		}
#endif
		glfwSetWindowSizeCallback(handle, callback);
#ifdef GEMSTONE_DEBUG
		m_WindowSizeCallbackInitialized = true;
#endif
	}

	float HumanInterfaceDeviceContext::GetTime() const {
		return (float)glfwGetTime();
	}

	void HumanInterfaceDeviceContext::Wait(const float seconds) const {
		const float endTime = GetTime() + seconds;

		while (GetTime() < endTime) { }
	}
}