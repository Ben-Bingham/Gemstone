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

	private:
		Vector2ui m_Size{ 640, 480 };
		WindowHandle m_Handle{ nullptr };
	};
}