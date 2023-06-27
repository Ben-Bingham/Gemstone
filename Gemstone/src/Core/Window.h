#pragma once
#include "Input/HumanInterfaceDeviceContext.h"
#include "Math/Vector.h"

namespace Gem {
	void WindowSizeCallback(WindowHandle handle, int width, int height);

	class Window : ISubSystem {
	public:
		Window() = default;

		[[nodiscard]] bool IsOpen() const;
		void Close();

		[[nodiscard]] WindowHandle Handle() const;

		void StartUp() override;
		void ShutDown() override;

		void SwapBuffers();

		void SwapInterval(size_t interval);

		void DisableCursor();
		void EnableCursor();

		Vector2ui size{ 640, 480 };

	private:
		WindowHandle m_Handle{ nullptr };
	};
}