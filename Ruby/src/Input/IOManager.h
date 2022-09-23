#pragma once

#include "Mouse.h"
#include "Keyboard.h"

namespace Ruby {
	class IOManager {
	public:
		IOManager() {}

		Keyboard keyboard;
		Mouse mouse;
	};
}