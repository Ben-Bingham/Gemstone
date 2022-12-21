#include "Transform.h"
#include "Log.h"

namespace Malachite {
	Transform::Transform(const Vector3f& position, const Vector3f& scale, const Rotation& rotation)
		: position(position), scale(scale), rotation(rotation) {

	}
}