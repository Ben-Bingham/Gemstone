#pragma once

#include "Mouse.h"
#include "Keyboard.h"

namespace Wavellite {
	class Window;

	class IOManager {
	public:
		IOManager(Window& window);

		Keyboard keyboard;
		Mouse mouse;
		Window* window;
	};
}