#pragma once
#include "Input/GLFWContext.h"
#include "Gem.h"

namespace Gem {
	class Window : ISubSystem {
	public:
		Window() = default;
		~Window() = default;

		Window(const Window& other) = delete;
		Window(Window&& other) noexcept = default;
		Window& operator=(const Window& other) = delete;
		Window& operator=(Window&& other) noexcept = default;

		void StartUp() override;
		void ShutDown() override;

		void SwapBuffers();

		Vector2ui size{ 640, 480 };

	private:
		WindowHandle m_Handle{ nullptr };
	};
}