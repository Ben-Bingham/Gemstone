#include "pch.h"

#include "Mouse.h"
#include "Wavellite/Window.h"

namespace Gem {
	void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
		Mouse& mouse = HumanInterfaceDeviceContext::GetPointerToUserData<Mouse>(window, "Mouse");

		switch (button) {
		case GLFW_MOUSE_BUTTON_1: mouse.button1 = Mouse::GLFWToState(action); break;
		case GLFW_MOUSE_BUTTON_2: mouse.button2 = Mouse::GLFWToState(action); break;
		case GLFW_MOUSE_BUTTON_3: mouse.button3 = Mouse::GLFWToState(action); break;
		default:
			LOG("Unknown mouse button inputted", Lazuli::LogLevel::WARNING);
		}

		for (auto& callback : mouse.buttonCallbacks) {
			callback(mouse);
		}
	}

	void MousePositionCallback(GLFWwindow* window, double xPos, double yPos) {
		Mouse& mouse = HumanInterfaceDeviceContext::GetPointerToUserData<Mouse>(window, "Mouse");

		mouse.yPosition = (int)xPos;
		mouse.xPosition = (int)yPos;

		for (auto& callback : mouse.positionCallbacks) {
			callback(mouse);
		}
	}

	void MouseScrollWheelCallback(GLFWwindow* window, double xOffset, double yOffset) {
		Mouse& mouse = HumanInterfaceDeviceContext::GetPointerToUserData<Mouse>(window, "Mouse");

		mouse.xScrollOffset = xOffset;
		mouse.yScrollOffset = yOffset;

		for (auto& callback : mouse.scrollCallbacks) {
			callback(mouse);
		}
	}

	void CursorEnterCallback(GLFWwindow* window, int entered) {
		Mouse& mouse = HumanInterfaceDeviceContext::GetPointerToUserData<Mouse>(window, "Mouse");

		entered ? mouse.overWindow = true : mouse.overWindow = false;

		for (auto& callback : mouse.enterCallbacks) {
			callback(mouse);
		}
	}

	Mouse::Mouse(Window& window, HumanInterfaceDeviceContext& hidContext)
		: m_Window(window), m_HidContext(hidContext) {

		m_HidContext.SetMouseButtonCallback(m_Window.Handle(), MouseButtonCallback);
		m_HidContext.SetMousePositionCallback(m_Window.Handle(), MousePositionCallback);
		m_HidContext.SetScrollCallback(m_Window.Handle(), MouseScrollWheelCallback);
		m_HidContext.SetCursorEnterCallback(m_Window.Handle(), CursorEnterCallback);

		m_HidContext.SetPointerToUserData(window.Handle(), "Mouse", *this);
	}

	MouseButtonState Mouse::GLFWToState(int state) {
		switch (state) {
		default:
		case GLFW_PRESS: return  BUTTON_PRESSED;
		case GLFW_RELEASE: return  BUTTON_RELEASED;
		}
	}

	void Mouse::SetButtonCallback(void(*callback)(Mouse& mouse)) {
		buttonCallbacks.push_back(callback);
	}

	void Mouse::SetPositionCallback(void(*callback)(Mouse& mouse)) {
		positionCallbacks.push_back(callback);
	}

	void Mouse::SetScrollCallback(void(*callback)(Mouse& mouse)) {
		scrollCallbacks.push_back(callback);
	}

	void Mouse::SetEnterWindowCallback(void(*callback)(Mouse& mouse)) {
		enterCallbacks.push_back(callback);
	}
}