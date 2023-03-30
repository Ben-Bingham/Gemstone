#include "pch.h"

#include <GLFW/glfw3.h>

#include "HumanInterfaceDeviceContext.h"
#include "Math/Vector.h"
#include "Utility/Log.h"

namespace Gem {
	void ErrorCallback(const int error, const char* description) {
		LOG("GLFW error: " + std::to_string(error) + std::string(description), LogLevel::ERROR);
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

	WindowHandle HumanInterfaceDeviceContext::CreateWindowHandle(const Vector2i& size, const std::string& title) const {
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
}