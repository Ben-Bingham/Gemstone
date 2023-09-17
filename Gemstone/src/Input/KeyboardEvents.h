#pragma once
#include "Keys.h"

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