#pragma once
#include "MouseButton.h"
#include "Gem.h"

namespace Gem::MouseEvents {
	GEM_API struct ButtonDown {
		MouseButton button;
	};

	GEM_API struct ButtonUp {
		MouseButton button;
	};

	GEM_API struct Position {
		int x;
		int y;
	};

	GEM_API struct Scroll {
		float x;
		float y;
	};

	GEM_API struct CursorEnter { };
	GEM_API struct CursorLeave { };
}