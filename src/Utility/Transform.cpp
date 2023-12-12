#include "pch.h"
#include "Transform.h"

namespace Gem {
	Transform::Transform(const Vector3f& position, const Vector3f& scale, const Vector3f& rotation)
		: position(position), scale(scale), rotation(rotation) {}

	Matrix4f Transform::Matrix() const {
		Matrix4f model{ 1.0f };

		model.translate(position).scale(scale).rotate(degreesToRadians(rotation.z), Vector3f::south).rotate(degreesToRadians(rotation.x), Vector3f::east).rotate(degreesToRadians(rotation.y), Vector3f::up);

		return model;
	}
}