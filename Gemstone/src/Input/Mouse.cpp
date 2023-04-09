#include "pch.h"
#include "Mouse.h"
#include "MouseEvents.h"
#include "Core/Engine.h"
#include "Core/Event System/EventHandler.h"
#include "Utility/Log.h"

namespace Gem {
	void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
		auto eventButton{MouseEvents::Button::UNKNOWN};

		switch (button) {
		case GLFW_MOUSE_BUTTON_1: eventButton = MouseEvents::Button::LEFT;
			break;
		case GLFW_MOUSE_BUTTON_2: eventButton = MouseEvents::Button::RIGHT;
			break;
		case GLFW_MOUSE_BUTTON_3: eventButton = MouseEvents::Button::MIDDLE;
			break;
		default:
			LOG("Unknown mouse button inputted", LogLevel::WARNING);
		}

		if (action) {
			g_Engine.eventManager.Post(MouseEvents::ButtonDown{eventButton});
		}
		else {
			g_Engine.eventManager.Post(MouseEvents::ButtonUp{eventButton});
		}
	}

	void MousePositionCallback(GLFWwindow* window, double xPos, double yPos) {
		g_Engine.eventManager.Post(MouseEvents::Position{static_cast<int>(xPos), static_cast<int>(yPos)});
	}

	void MouseScrollWheelCallback(GLFWwindow* window, double xOffset, double yOffset) {
		g_Engine.eventManager.Post(MouseEvents::Scroll{static_cast<float>(xOffset), static_cast<float>(yOffset)});
	}

	void CursorEnterCallback(GLFWwindow* window, int entered) {
		if (entered) {
			g_Engine.eventManager.Post(MouseEvents::CursorEnter{});
		}
		else {
			g_Engine.eventManager.Post(MouseEvents::CursorLeave{});
		}
	}

	void Mouse::StartUp() {
		const Window& window = g_Engine.window;
		HumanInterfaceDeviceContext& hidContext = g_Engine.humanInterfaceDeviceContext;

		hidContext.SetMouseButtonCallback(window.Handle(), MouseButtonCallback);
		hidContext.SetMousePositionCallback(window.Handle(), MousePositionCallback);
		hidContext.SetScrollCallback(window.Handle(), MouseScrollWheelCallback);
		hidContext.SetCursorEnterCallback(window.Handle(), CursorEnterCallback);
	}

	void Mouse::ShutDown() {
		
	}
}