#pragma once
#include <vector>

#include "Matrix.h"

namespace Malachite {
	using Rotation = Vector3<Degree>;

	class Transform {
	public:
		Transform(const Vector3f& position = Vector3f{ 0.0f }, const Vector3f& scale = Vector3f{ 1.0f }, const Rotation& rotation = Rotation{ 0.0f });

		Vector3f position;
		Vector3f scale;
		Rotation rotation;

		[[nodiscard]] Matrix4f getModelMatrix() const {
			Matrix4f mat{};
			mat.translate(position).scale(scale).rotate(rotation.x, Vector3f::east).rotate(rotation.y, Vector3f::up).rotate(rotation.z, Vector3f::south);
			return mat;
		}
	};
}