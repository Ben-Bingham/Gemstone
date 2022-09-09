#pragma once

#include "vector/Vector.h"

namespace Malachite {
	template<typename T>
	class Matrix4x4 {
	public:
		Matrix4x4() {}
		Matrix4x4(T val) : row1(val), row2(val), row3(val), row4(val) {}
		Matrix4x4(Vector4<T> Row1, Vector4<T> Row2, Vector4<T> Row3, Vector4<T> Row4) : row1(Row1), row2(Row2), row3(Row3), row4(Row4) {}

		Vector4<T> row1{ };
		Vector4<T> row2{ };
		Vector4<T> row3{ };
		Vector4<T> row4{ };

		// +=
		Matrix4x4<T>& operator+=(const Matrix4x4<T>& mat) {
			row1 += mat.row1;
			row2 += mat.row2;
			row3 += mat.row3;
			row4 += mat.row4;
			return *this;
		}

		Matrix4x4<T>& operator+=(const T& scaler) {
			*this += Matrix4x4<T>{ scaler };
			return *this;
		}

		// -=
		Matrix4x4<T>& operator-=(const Matrix4x4<T>& mat) {
			row1 -= mat.row1;
			row2 -= mat.row2;
			row3 -= mat.row3;
			row4 -= mat.row4;
			return *this;
		}

		Matrix4x4<T>& operator-=(const T& scaler) {
			*this -= Matrix4x4<T>{ scaler };
			return *this;
		}

		//  TODO should be replaced with cross or dot or whateverS
		Matrix4x4<T>& operator*=(const Matrix4x4<T>& mat) {
			row1 *= mat.row1;
			row2 *= mat.row2;
			row3 *= mat.row3;
			row4 *= mat.row4;
			return *this;
		}

		Matrix4x4<T>& operator*=(const T& scaler) {
			*this *= Matrix4x4<T>{ scaler };
			return *this;
		}

		// /=
		Matrix4x4<T>& operator/=(const Matrix4x4<T>& mat) {
			row1 /= mat.row1;
			row2 /= mat.row2;
			row3 /= mat.row3;
			row4 /= mat.row4;
			return *this;
		}

		Matrix4x4<T>& operator/=(const T& scaler) {
			*this /= Matrix4x4<T>{ scaler };
			return *this;
		}
	};
}