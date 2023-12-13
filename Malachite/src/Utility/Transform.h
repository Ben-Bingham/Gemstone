#pragma once
#include "Matrix.h"

namespace Malachite {
	using Rotation = Vector3<Degree>;

	class Transform {
	public:
		Transform(const Vector3f& position = Vector3f{ 0.0f }, const Vector3f& scale = Vector3f{ 1.0f }, const Rotation& rotation = Rotation{ 0.0f });

		Vector3f& position() {
			m_Modified = true;
			return m_Position;
		}
		[[nodiscard]] Vector3f position() const { return m_Position; }

		Vector3f& scale() {
			m_Modified = true;
			return m_Scale;
		}
		[[nodiscard]] Vector3f scale() const { return m_Scale; }

		Rotation& rotation() {
			m_Modified = true;
			return m_Rotation;
		}
		[[nodiscard]] Rotation rotation() const { return m_Rotation; }

		[[nodiscard]] Matrix4f getModelMatrix();

	private:
		Vector3f m_Position;
		Vector3f m_Scale;
		Rotation m_Rotation;

		bool m_Modified{ false };
		Matrix4f m_ModelMatrix{ 1.0f };
	};
}