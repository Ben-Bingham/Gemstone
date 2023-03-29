#pragma once
#include <GLFW/glfw3.h>

#include "Wavellite/HumanInterfaceDeviceContext.h"
#include "Wavellite/Window.h"

namespace Gem {
	enum MouseButtonState {
		BUTTON_RELEASED = 0,
		BUTTON_PRESSED = 1
	};

	void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
	void MousePositionCallback(GLFWwindow* window, double xPos, double yPos);
	void MouseScrollWheelCallback(GLFWwindow* window, double xOffset, double yOffset);
	void CursorEnterCallback(GLFWwindow* window, int entered);

	class Mouse {
	public:
		Mouse(Window& window, HumanInterfaceDeviceContext& hidContext);

		static MouseButtonState GLFWToState(int state);

		void SetButtonCallback(void(*callback)(Mouse& mouse));
		void SetPositionCallback(void(*callback)(Mouse& mouse));
		void SetScrollCallback(void(*callback)(Mouse& mouse));
		void SetEnterWindowCallback(void(*callback)(Mouse& mouse));

	private:
		Window& m_Window;
		HumanInterfaceDeviceContext& m_HidContext;

	public:
		std::vector<void(*)(Mouse& mouse)> buttonCallbacks;
		std::vector<void(*)(Mouse& mouse)> positionCallbacks;
		std::vector<void(*)(Mouse& mouse)> scrollCallbacks;
		std::vector<void(*)(Mouse& mouse)> enterCallbacks;


		int xPosition{ 0 };
		int yPosition{ 0 };

		float xScrollOffset{ 0.0f };
		float yScrollOffset{ 0.0f };

		bool overWindow{ true };

		MouseButtonState button1{ BUTTON_RELEASED }; // Left
		MouseButtonState button2{ BUTTON_RELEASED }; // Right
		MouseButtonState button3{ BUTTON_RELEASED }; // Middle
	};
}