#pragma once
#include "Input/HumanInterfaceDeviceContext.h"
#include "Math/Vector.h"

namespace Gem {
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

		[[nodiscard]] Vector2ui Size() const;

	private:
		Vector2ui m_Size{ 640, 480 };
		WindowHandle m_Handle{ nullptr };
	};
}