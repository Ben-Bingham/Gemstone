#pragma once
#include "Input/HumanInterfaceDeviceContext.h"
#include "Math/Vector.h"

namespace Gem {
	class Window {
	public:
		Window(HumanInterfaceDeviceContext& hidContext);

		[[nodiscard]] bool IsOpen() const;
		void Close() const;

		[[nodiscard]] WindowHandle Handle() const;

	private:
		HumanInterfaceDeviceContext& m_HidContext;
		Vector2i m_Size{ 640, 480 };
		WindowHandle m_Handle{ nullptr };
	};
}