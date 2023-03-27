#include "pch.h"
#include "Transform.h"

namespace Malachite {
	Transform::Transform(const Vector3f& position, const Vector3f& scale, const Rotation& rotation)
		: m_Position(position), m_Scale(scale), m_Rotation(rotation) {

	}

	[[nodiscard]] Matrix4f Transform::getModelMatrix() {
		if (m_Modified) {
			m_ModelMatrix = Matrix4f{ 1.0f };
			m_ModelMatrix.translate(m_Position).scale(m_Scale).rotate(m_Rotation.x, Vector3f::east).rotate(m_Rotation.y, Vector3f::up).rotate(m_Rotation.z, Vector3f::south);
			m_Modified = false;
		}
		
		return m_ModelMatrix;
	}
}