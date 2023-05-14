#pragma once

#include "Math/Matrix.h"
#include "Math/Vector.h"

namespace Gem {
	struct Transform {
		Transform(
			const Vector3f& position = Vector3f{ 0.0f }, 
			const Vector3f& scale = Vector3f{ 1.0f }, 
			const Vector3f& rotation = Vector3f{ 0.0f }
		);

		Vector3f position;
		Vector3f scale;
		Vector3f rotation; // Degrees

		[[nodiscard]] Matrix4f Matrix() const;
	};
}