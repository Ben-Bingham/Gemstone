#include "Transform.h"
#include "Log.h"

namespace Malachite {
	void Transform::compileTransformations() {
		Matrix4f transform{ 1.0f };
		for (const Matrix4f& transformation : m_Transformations) {
			transform = transform * transformation;
		}

		m_Matrix = transform;
	}

	void Transform::translate(const Vector3f& translation) {
		m_Transformations.push_back(Matrix4f{ 1.0 }.translate(translation));
	}

	void Transform::scale(const Vector3f& scale) {
#ifdef MALACHITE_DEBUG
		if (scale.x == 0.0f || scale.y == 0.0f || scale.z == 0.0f) {
			LOG("Attempting to scale with a factor of 0. Use a factor of 1 for no change.", Lazuli::LogLevel::WARNING);
		}
#endif
		m_Transformations.push_back(Matrix4f{ 1.0 }.scale(scale));
	}

	void Transform::rotate(const Vector3f& rotation) {

	}

	void Transform::addTransformation(const Matrix4f& transformation) {
		m_Transformations.push_back(transformation);
	}
}