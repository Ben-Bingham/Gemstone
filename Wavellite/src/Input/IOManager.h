#pragma once

#include "Mouse.h"
#include "Keyboard.h"

namespace Wavellite {
	class Window;

	class IOManager {
	public:
		IOManager(Window& window);

		Keyboard keyboard; // TODO make private and replace with a getKeyboard function. Same for mouse (should return pointer)
		Mouse mouse;
		Window* window;
	};
}