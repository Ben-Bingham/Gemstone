#pragma once

#include "Mouse.h"
#include "Keyboard.h"

namespace Wavellite {
	class IOManager {
	public:
		IOManager() {}

		Keyboard keyboard;
		Mouse mouse;
	};
}