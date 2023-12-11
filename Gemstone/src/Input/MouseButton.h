#pragma once
#include <GLFW/glfw3.h>
#include "Gem.h"

namespace Gem {
	enum class MouseButton {
		LEFT = GLFW_MOUSE_BUTTON_LEFT,
		MIDDLE = GLFW_MOUSE_BUTTON_MIDDLE,
		RIGHT = GLFW_MOUSE_BUTTON_RIGHT,
		UNKNOWN = -1
	};
}