#pragma once
#include "Camera.h"
#include "Utility/Transform.h"

namespace Gem {
	struct CameraObject {
		Camera camera;
		Transform transform;
	};
}