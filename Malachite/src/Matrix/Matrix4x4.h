#pragma once

#include "vector/Vector.h"

namespace Malachite {
	template<typename T>
	class Matrix4x4 {
	public:
		Matrix4x4() {}
		Matrix4x4(T val) : row1(val), row2(val), row3(val), row4(val) {}
		Matrix4x4(Vector4<T> Row1, Vector4<T> Row2, Vector4<T> Row3, Vector4<T> Row4) : row1(Row1), row2(Row2), row3(Row3), row4(Row4) {}

		Matrix4x4(
			T r1x, T r1y, T r1z, T r1w,
			T r2x, T r2y, T r2z, T r2w,
			T r3x, T r3y, T r3z, T r3w,
			T r4x, T r4y, T r4z, T r4w 
			) : 
			row1(r1x, r1y, r1z, r1w),
			row2(r2x, r2y, r2z, r2w),
			row3(r3x, r3y, r3z, r3w),
			row4(r4x, r4y, r4z, r4w)
		{}


		Vector4<T> row1{ };
		Vector4<T> row2{ };
		Vector4<T> row3{ };
		Vector4<T> row4{ };

		Matrix4x4<T>& operator*=(const Matrix4x4<T>& mat) {
			row1 *= mat.row1;
			row2 *= mat.row2;
			row3 *= mat.row3;
			row4 *= mat.row4;
			return *this;
		}
	};

	// *
	template<typename T>
	inline Matrix4x4<T> operator*(const Matrix4x4<T>& mat1, const Matrix4x4<T>& mat2) { //TODO testing
		return Matrix4x4<T>(
			// Row 1
			mat1.row1.x * mat2.row1.x + mat1.row1.y * mat2.row2.x + mat1.row1.z * mat2.row3.x + mat1.row1.w * mat2.row4.x,
			mat1.row1.x * mat2.row1.y + mat1.row1.y * mat2.row2.y + mat1.row1.z * mat2.row3.y + mat1.row1.w * mat2.row4.y,
			mat1.row1.x * mat2.row1.z + mat1.row1.y * mat2.row2.z + mat1.row1.z * mat2.row3.z + mat1.row1.w * mat2.row4.z,
			mat1.row1.x * mat2.row1.w + mat1.row1.y * mat2.row2.w + mat1.row1.z * mat2.row3.w + mat1.row1.w * mat2.row4.w,

			// Row 2
			mat1.row2.x * mat2.row1.x + mat1.row2.y * mat2.row2.x + mat1.row2.z * mat2.row3.x + mat1.row2.w * mat2.row4.x,
			mat1.row2.x * mat2.row1.y + mat1.row2.y * mat2.row2.y + mat1.row2.z * mat2.row3.y + mat1.row2.w * mat2.row4.y,
			mat1.row2.x * mat2.row1.z + mat1.row2.y * mat2.row2.z + mat1.row2.z * mat2.row3.z + mat1.row2.w * mat2.row4.z,
			mat1.row2.x * mat2.row1.w + mat1.row2.y * mat2.row2.w + mat1.row2.z * mat2.row3.w + mat1.row2.w * mat2.row4.w,

			// Row 3
			mat1.row3.x * mat2.row1.x + mat1.row3.y * mat2.row2.x + mat1.row3.z * mat2.row3.x + mat1.row3.w * mat2.row4.x,
			mat1.row3.x * mat2.row1.y + mat1.row3.y * mat2.row2.y + mat1.row3.z * mat2.row3.y + mat1.row3.w * mat2.row4.y,
			mat1.row3.x * mat2.row1.z + mat1.row3.y * mat2.row2.z + mat1.row3.z * mat2.row3.z + mat1.row3.w * mat2.row4.z,
			mat1.row3.x * mat2.row1.w + mat1.row3.y * mat2.row2.w + mat1.row3.z * mat2.row3.w + mat1.row3.w * mat2.row4.w,

			// Row 4
			mat1.row4.x * mat2.row1.x + mat1.row4.y * mat2.row2.x + mat1.row4.z * mat2.row3.x + mat1.row4.w * mat2.row4.x,
			mat1.row4.x * mat2.row1.y + mat1.row4.y * mat2.row2.y + mat1.row4.z * mat2.row3.y + mat1.row4.w * mat2.row4.y,
			mat1.row4.x * mat2.row1.z + mat1.row4.y * mat2.row2.z + mat1.row4.z * mat2.row3.z + mat1.row4.w * mat2.row4.z,
			mat1.row4.x * mat2.row1.w + mat1.row4.y * mat2.row2.w + mat1.row4.z * mat2.row3.w + mat1.row4.w * mat2.row4.w,
			);
	}
}