#pragma once

namespace Gem::KeyboardEvents {
	struct KeyDown {
		Key key;
	};

	struct KeyHeld {
		Key key;
	};

	struct KeyUp {
		Key key;
	};
}