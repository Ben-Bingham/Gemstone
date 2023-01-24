#include "Mouse.h"
#include "IOManager.h"
#include "Window.h"

namespace Wavellite {
	Mouse& Mouse::Get() {
		static Mouse mouse;
		return mouse;
	}

	void Mouse::Init() {
		if (m_Initialized) {
			return;
		}

		glfwSetScrollCallback(Window::Get().getWindow(), mouseScrollWheelCallback);
		glfwSetMouseButtonCallback(Window::Get().getWindow(), mouseButtonCallback);
		glfwSetCursorEnterCallback(Window::Get().getWindow(), cursorEnterCallback);
		glfwSetCursorPosCallback(Window::Get().getWindow(), mousePositionCallback);

		m_Initialized = true;
	}

	void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
		IOManager* manager = (IOManager*)glfwGetWindowUserPointer(window);
		Mouse& mouse = *manager->mouse;

		switch (button) {
		case GLFW_MOUSE_BUTTON_1: mouse.button1 = intToMouseState(action); break;
		case GLFW_MOUSE_BUTTON_2: mouse.button2 = intToMouseState(action); break;
		case GLFW_MOUSE_BUTTON_3: mouse.button3 = intToMouseState(action); break;
		}
	}

	void mousePositionCallback(GLFWwindow* window, double xpos, double ypos) {
		IOManager* manager = (IOManager*)glfwGetWindowUserPointer(window);
		Mouse& mouse = *manager->mouse;

		mouse.yPosition = (int)ypos;
		mouse.xPosition = (int)xpos;

		int count{ 0 };
		for (void (*callback)(int xpos, int ypos, void* data) : mouse.mousePositionCallbacks) {
			callback((int)xpos, (int)ypos, mouse.mousePositionCallbackData[count]);
			count++;
		}
	}

	void mouseScrollWheelCallback(GLFWwindow* window, double xoffset, double yoffset) {
		IOManager* manager = (IOManager*)glfwGetWindowUserPointer(window);
		Mouse& mouse = *manager->mouse;

		int count{ 0 };
		for (void (*callback)(int xoffset, int yoffset, void* data) : mouse.scrollCallbacks) {
			callback((int)xoffset, (int)yoffset, mouse.scrollCallbacksData[count]);
			count++;
		}
	}

	void cursorEnterCallback(GLFWwindow* window, int entered) {}

	MouseButtonState intToMouseState(int state) {
		switch (state) {
		default:
		case GLFW_PRESS: return  MouseButtonState::BUTTON_PRESSED;
		case GLFW_RELEASE: return  MouseButtonState::BUTTON_RELEASED;
		}
	}
}