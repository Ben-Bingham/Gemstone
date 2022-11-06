#pragma once

#include "Mouse.h"
#include "Keyboard.h"

namespace Wavellite {
	class Window;

	class IOManager {
	public:
		IOManager(Window& window);

		Window* window;

		Keyboard* getKeyboard();
		Mouse* getMouse();
	private:
		Keyboard m_Keyboard;
		Mouse m_Mouse;
	};
}