#include "pch.h"
#include "Mouse.h"
#include "MouseEvents.h"
#include "Core/Engine.h"
#include "Core/Event System/EventHandler.h"
#include "Utility/Log.h"

namespace Gem {
	void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
		auto eventButton{ MouseButton::UNKNOWN };

		switch (button) {
		case GLFW_MOUSE_BUTTON_1: eventButton = MouseButton::LEFT;
			break;
		case GLFW_MOUSE_BUTTON_2: eventButton = MouseButton::RIGHT;
			break;
		case GLFW_MOUSE_BUTTON_3: eventButton = MouseButton::MIDDLE;
			break;
		default:
			LOG("Unknown mouse button inputted", LogLevel::WARNING);
		}

		if (action) {
			//g_Engine.eventManager.Post(MouseEvents::ButtonDown{eventButton});
		}
		else {
			//g_Engine.eventManager.Post(MouseEvents::ButtonUp{eventButton});
		}
	}

	void MousePositionCallback(GLFWwindow* window, double xPos, double yPos) {
		//g_Engine.eventManager.Post(MouseEvents::Position{static_cast<int>(xPos), static_cast<int>(yPos)});
	}

	void MouseScrollWheelCallback(GLFWwindow* window, double xOffset, double yOffset) {
		//g_Engine.eventManager.Post(MouseEvents::Scroll{static_cast<float>(xOffset), static_cast<float>(yOffset)});
	}

	void CursorEnterCallback(GLFWwindow* window, int entered) {
		if (entered) {
			//g_Engine.eventManager.Post(MouseEvents::CursorEnter{});
		}
		else {
			//g_Engine.eventManager.Post(MouseEvents::CursorLeave{});
		}
	}

	void Mouse::StartUp() {
		//const Window& window = g_Engine.window;
		//HumanInterfaceDeviceContext& hidContext = g_Engine.humanInterfaceDeviceContext;

		//hidContext.SetMouseButtonCallback(window.Handle(), MouseButtonCallback);
		//hidContext.SetMousePositionCallback(window.Handle(), MousePositionCallback);
		//hidContext.SetScrollCallback(window.Handle(), MouseScrollWheelCallback);
		//hidContext.SetCursorEnterCallback(window.Handle(), CursorEnterCallback);
	}

	void Mouse::ShutDown() { }

	Vector2i Mouse::GetPosition() const {
		//return g_Engine.humanInterfaceDeviceContext.GetMousePosition(g_Engine.window.Handle());
		return Vector2i{};
	}

	bool Mouse::GetButton(MouseButton button) const {
		return false;
		//return g_Engine.humanInterfaceDeviceContext.GetMouseButton(g_Engine.window.Handle(), button);
	}
}