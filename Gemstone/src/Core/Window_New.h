#pragma once
#include "Input/GLFWContext.h"

namespace Gem {
	class Window_New {
	public:
		Window_New();
		~Window_New();

		Window_New(const Window_New& other) = delete;
		Window_New(Window_New&& other) noexcept = default;
		Window_New& operator=(const Window_New& other) = delete;
		Window_New& operator=(Window_New&& other) noexcept = default;

		void SwapBuffers();

		Vector2ui size{ 640, 480 };

	private:
		WindowHandle m_Handle{ nullptr };
	};
}