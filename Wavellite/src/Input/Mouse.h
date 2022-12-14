#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

namespace Wavellite {
	enum MouseButtonState {
		BUTTON_RELEASED = 0,
		BUTTON_PRESSED = 1
	};

	void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
	void mousePositionCallback(GLFWwindow* window, double xpos, double ypos);
	void mouseScrollWheelCallback(GLFWwindow* window, double xoffset, double yoffset);
	void cursorEnterCallback(GLFWwindow* window, int entered);

	class Mouse {
	public:
		Mouse() = default;
		Mouse(const Mouse&) = delete;
		const Mouse& operator=(const Mouse&) = delete;
		Mouse(Mouse&&) = default;
		Mouse& operator=(Mouse&&) = default;
		~Mouse() = default;

		int xPosition{ 0 };
		int yPosition{ 0 };

		MouseButtonState button1{ MouseButtonState::BUTTON_RELEASED }; // Left
		MouseButtonState button2{ MouseButtonState::BUTTON_RELEASED }; // Right
		MouseButtonState button3{ MouseButtonState::BUTTON_RELEASED }; // Middle

		bool hasMoved{ false };

		void addScrollCallback(void (*callback)(int xoffset, int yoffset, void* data), void* data) {
			scrollCallbacks.push_back(callback);
			scrollCallbacksData.push_back(data);
		}

		void addMousePositionCallback(void (*callback)(int xpos, int ypos, void* data), void* data) {
			mousePositionCallbacks.push_back(callback);
			mousePositionCallbackData.push_back(data);
		}

		std::vector<void (*)(int xoffset, int yoffset, void* data)> scrollCallbacks;
		std::vector<void*> scrollCallbacksData;

		std::vector<void (*)(int xpos, int ypos, void* data)> mousePositionCallbacks;
		std::vector<void*> mousePositionCallbackData;
	};

	MouseButtonState intToMouseState(int state);
}