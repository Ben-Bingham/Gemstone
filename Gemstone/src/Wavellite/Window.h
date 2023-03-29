#pragma once
#include "HumanInterfaceDeviceContext.h"
#include "Malachite/Vector.h"

namespace Gem {
	class Window {
	public:
		Window(HumanInterfaceDeviceContext& hidContext);

		[[nodiscard]] bool IsOpen() const;
		void Close() const;

		[[nodiscard]] WindowHandle Handle() const;

	private:
		HumanInterfaceDeviceContext& m_HidContext;
		Malachite::Vector2i m_Size{ 640, 480 };
		WindowHandle m_Handle{ nullptr };
	};
}