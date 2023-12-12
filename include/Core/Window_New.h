#pragma once
#include "Input/GLFWContext.h"
#include "Gem.h"

namespace Gem {
//<<<<<<< HEAD
	GEM_API class Window_New {
	public:
		Window_New();
		~Window_New();

		Window_New(const Window_New& other) = delete;
		Window_New(Window_New&& other) noexcept = default;
		Window_New& operator=(const Window_New& other) = delete;
		Window_New& operator=(Window_New&& other) noexcept = default;
//=======
//	class Window {
//	public:
//		Window();
//		~Window();
//
//		Window(const Window& other) = delete;
//		Window(Window&& other) noexcept = default;
//		Window& operator=(const Window& other) = delete;
//		Window& operator=(Window&& other) noexcept = default;
//>>>>>>> c45902e481ceeaa56edb35b99852a647fa53ac3e

		void SwapBuffers();

		Vector2ui size{ 640, 480 };

	private:
		WindowHandle m_Handle{ nullptr };
	};
}