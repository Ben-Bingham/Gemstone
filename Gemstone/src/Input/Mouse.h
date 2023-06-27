#pragma once
#include "MouseButton.h"

#include <GLFW/glfw3.h>

#include "Core/Window.h"

namespace Gem {
	void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
	void MousePositionCallback(GLFWwindow* window, double xPos, double yPos);
	void MouseScrollWheelCallback(GLFWwindow* window, double xOffset, double yOffset);
	void CursorEnterCallback(GLFWwindow* window, int entered);

	class Mouse : ISubSystem {
	public:
		Mouse() = default;

		void StartUp() override;
		void ShutDown() override;

		Vector2i GetPosition() const;
		bool GetButton(MouseButton button) const;
	};
}