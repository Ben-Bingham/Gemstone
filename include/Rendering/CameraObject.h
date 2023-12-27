#pragma once
#include "Camera_New.h"
#include "Utility/Transform.h"

namespace Gem {
	struct CameraObject {
		Camera_New camera;
		Transform transform;
	};
}