#pragma once
#include "GLFWContext.h"

namespace Gem {
	class Window {
		friend class Engine;

		static void StartUp();
		static void ShutDown();

		Window() = default;
		~Window() = default;

		static inline bool m_Started{ false };

	public:
		static Window& Get();

		Window(const Window& other) = delete;
		Window(Window&& other) noexcept = default;
		Window& operator=(const Window& other) = delete;
		Window& operator=(Window&& other) noexcept = default;

		void SwapBuffers();
		void SwapInterval(int interval);

		bool ShouldClose();

		Vector2ui size{ 640, 480 };

	private:
		WindowHandle m_Handle{ nullptr };
	};
}