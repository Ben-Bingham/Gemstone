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
		Mouse(const Mouse&) = delete;
		const Mouse& operator=(const Mouse&) = delete;
		Mouse(Mouse&&) = delete;
		Mouse& operator=(Mouse&&) = delete;
		~Mouse() = default;

		static Mouse& Get();
		void Init();

		int xPosition{ 0 };
		int yPosition{ 0 };

		float xScrollOffset{ 0.0f };
		float yScrollOffset{ 0.0f };

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

		std::vector<void (*)(int xoffset, int yoffset, void* data)> scrollCallbacks; //TODO make private
		std::vector<void*> scrollCallbacksData;

		std::vector<void (*)(int xpos, int ypos, void* data)> mousePositionCallbacks;
		std::vector<void*> mousePositionCallbackData;

	private:
		Mouse() = default;

		bool m_Initialized{ false };
	};

	MouseButtonState intToMouseState(int state);
}