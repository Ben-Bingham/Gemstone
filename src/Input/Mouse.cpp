#include "Input/Mouse.h"
#include "Input/MouseEvents.h"
#include "Core/Window.h"
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
			EventSystem::Get().Post(MouseEvents::ButtonDown{ eventButton });
		}
		else {
			EventSystem::Get().Post(MouseEvents::ButtonUp{ eventButton });
		}
	}

	void MousePositionCallback(GLFWwindow* window, double xPos, double yPos) {
		EventSystem::Get().Post(MouseEvents::Position{ static_cast<int>(xPos), static_cast<int>(yPos) });
	}

	void MouseScrollWheelCallback(GLFWwindow* window, double xOffset, double yOffset) {
		EventSystem::Get().Post(MouseEvents::Scroll{ static_cast<float>(xOffset), static_cast<float>(yOffset) });
	}

	void CursorEnterCallback(GLFWwindow* window, int entered) {
		if (entered) {
			EventSystem::Get().Post(MouseEvents::CursorEnter{ });
		}
		else {
			EventSystem::Get().Post(MouseEvents::CursorLeave{ });
		}
	}

	void Mouse::StartUp() {
		m_Started = true;

		Window& window = Window::Get();
		window.SetMouseButtonCallback(MouseButtonCallback);
		window.SetMousePositionCallback(MousePositionCallback);
		window.SetScrollWheelCallback(MouseScrollWheelCallback);
		window.SetCursorEnterCallback(CursorEnterCallback);
	}

	void Mouse::ShutDown() {
		m_Started = false;
	}

	Mouse& Mouse::Get() {
		if (!m_Started) {
			LOG("Failed to StartUp Mouse, before using it.", LogLevel::TERMINAL);
		}

		static Mouse mouse;
		return mouse;
	}

	Vector2i Mouse::GetPosition() const {
		return Window::Get().GetMousePosition();
	}

	bool Mouse::GetButton(const MouseButton button) const {
		return Window::Get().GetMouseButton(button);
	}
}