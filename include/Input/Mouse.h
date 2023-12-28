#pragma once
#include <GLFW/glfw3.h>
#include "MouseButton.h"
#include "Math/Vector.h"

namespace Gem {
	void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
	void MousePositionCallback(GLFWwindow* window, double xPos, double yPos);
	void MouseScrollWheelCallback(GLFWwindow* window, double xOffset, double yOffset);
	void CursorEnterCallback(GLFWwindow* window, int entered);

	class Mouse {
		friend class Engine;

		static void StartUp();
		static void ShutDown();

		Mouse() = default;
		~Mouse() = default;

		static inline bool m_Started{ false };

	public:
		static Mouse& Get();

		Mouse(const Mouse& other) = delete;
		Mouse(Mouse&& other) noexcept = default;
		Mouse& operator=(const Mouse& other) = delete;
		Mouse& operator=(Mouse&& other) noexcept = default;

		Vector2i GetPosition() const;
		bool GetButton(MouseButton button) const;
	};
}