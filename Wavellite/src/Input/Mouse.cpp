#include "Mouse.h"
#include "IOManager.h"

namespace Wavellite {
	void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
		IOManager* manager = (IOManager*)glfwGetWindowUserPointer(window);

		switch (button) {
		case GLFW_MOUSE_BUTTON_1: manager->mouse.button1 = intToMouseState(action); break;
		case GLFW_MOUSE_BUTTON_2: manager->mouse.button2 = intToMouseState(action); break;
		case GLFW_MOUSE_BUTTON_3: manager->mouse.button3 = intToMouseState(action); break;
		}
	}

	void mousePositionCallback(GLFWwindow* window, double xpos, double ypos) {
		IOManager* manager = (IOManager*)glfwGetWindowUserPointer(window);

		manager->mouse.yPosition = (int)ypos;
		manager->mouse.xPosition = (int)xpos;

		int count{ 0 };
		for (void (*callback)(int xpos, int ypos, void* data) : manager->mouse.mousePositionCallbacks) {
			callback((int)xpos, (int)ypos, manager->mouse.mousePositionCallbackData[count]);
			count++;
		}
	}

	void mouseScrolWheelCallback(GLFWwindow* window, double xoffset, double yoffset) {
		IOManager* manager = (IOManager*)glfwGetWindowUserPointer(window);

		int count{ 0 };
		for (void (*callback)(int xoffset, int yoffset, void* data) : manager->mouse.scrollCallbacks) {
			callback((int)xoffset, (int)yoffset, manager->mouse.scrollCallbacksData[count]);
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