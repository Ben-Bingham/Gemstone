#pragma once
#include "Gem.h"
#include "GLFWContext.h"
#include "ISubSystem.h"

namespace Gem {
	class Window : ISubSystem {
	public:
		Window(GLFWContext& glfwContext);
		~Window() override = default;

		Window(const Window& other) = delete;
		Window(Window&& other) noexcept = default;
		Window& operator=(const Window& other) = delete;
		Window& operator=(Window&& other) noexcept = default;

		void StartUp() override;
		void ShutDown() override;

		void SwapBuffers();
		void SwapInterval(int interval);

		bool ShouldClose();

		Vector2ui size{ 640, 480 };

	private:
		WindowHandle m_Handle{ nullptr };
		GLFWContext& m_Context;
	};
}