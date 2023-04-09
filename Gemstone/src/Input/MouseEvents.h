#pragma once

namespace Gem::MouseEvents {
	enum class Button {
		LEFT,
		MIDDLE,
		RIGHT,
		UNKNOWN
	};

	struct ButtonDown {
		Button button;
	};

	struct ButtonUp {
		Button button;
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