#pragma once
#include "Input/GLFWContext.h"

namespace Gem {
	class Window {
	public:
		Window();
		~Window();

		Window(const Window& other) = delete;
		Window(Window&& other) noexcept = default;
		Window& operator=(const Window& other) = delete;
		Window& operator=(Window&& other) noexcept = default;

		void SwapBuffers();

		Vector2ui size{ 640, 480 };

	private:
		WindowHandle m_Handle{ nullptr };
	};
}