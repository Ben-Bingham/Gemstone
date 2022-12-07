#pragma once
#include <vector>

#include "Matrix.h"

namespace Malachite {
	class Transform {
	public:
		Transform() = default;

		void compileTransformations();
		
		void translate(const Vector3f& translation);
		void scale(const Vector3f& scale);
		void rotate(const Vector3f& rotation);

		void addTransformation(const Matrix4f& transformation);

	private:
		std::vector<Matrix4f> m_Transformations;
		Matrix4f m_Matrix;
	};
}