#pragma once
#include "MouseButton.h"
#include "Gem.h"

namespace Gem::MouseEvents {
	struct GEM_API ButtonDown {
		MouseButton button;
	};

	struct GEM_API ButtonUp {
		MouseButton button;
	};

	struct GEM_API Position {
		int x;
		int y;
	};

	struct GEM_API Scroll {
		float x;
		float y;
	};

	struct GEM_API CursorEnter { };
	struct GEM_API CursorLeave { };
}