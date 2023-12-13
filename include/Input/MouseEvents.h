#pragma once
#include "MouseButton.h"
#include "Gem.h"

namespace Gem::MouseEvents {
	struct ButtonDown {
		MouseButton button;
	};

	struct ButtonUp {
		MouseButton button;
	};

	struct Position {
		int x;
		int y;
	};

	struct Scroll {
		float x;
		float y;
	};

	struct CursorEnter { };
	struct CursorLeave { };
}