#pragma once
#include <iostream>

#include "Vector.h"

namespace Malachite {
	template<typename T>
	class Matrix4x4 {
	public:
		Matrix4x4() {}
		Matrix4x4(T val) : row1(val, 0, 0, 0), row2(0, val, 0, 0), row3(0, 0, val, 0), row4(0, 0, 0, val) {}
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

		// Translation
		Matrix4x4<T>& translate(const Vector3<T>& vector) {
			row4 += Vector4<T>{ vector.x, vector.y, vector.z, 0 };
			return *this;
		}

		Matrix4x4<T>& translate(const T& x, const T& y, const T& z) {
			row4 += Vector4<T>{ x, y, z, 0 };
			return *this;
		}

		// Scale
		Matrix4x4<T>& scale(const Vector3<T>& vector) {
			row1.x *= vector.x;
			row2.y *= vector.y;
			row3.z *= vector.z;
			return *this;
		}

		Matrix4x4<T>& scale(const T& x, const T& y, const T& z) {
			row1.x *= x;
			row2.y *= y;
			row3.z *= z;			
			return *this;
		}

		Matrix4x4<T>& lookAt(const Vector3<T>& eye, const Vector3<T>& target, const Vector3<T>& up) { //TODO testing
			Vector3<T> direction(normalize(target - eye));
			Vector3<T> s(normalize(cross(direction, up))); // side??
			Vector3<T> relativeUp(cross(s, direction));

			Matrix4x4<T> result{ 1 };
			result.row1.x = s.x;
			result.row2.x = s.y;
			result.row3.x = s.z;
			result.row1.y = relativeUp.x;
			result.row2.y = relativeUp.y;
			result.row3.y = relativeUp.z;
			result.row1.z = -direction.x;
			result.row2.z = -direction.y;
			result.row3.z = -direction.z;
			result.row4.x = -dot(s, eye);
			result.row4.y = -dot(relativeUp, eye);
			result.row4.z = dot(direction, eye);
			*this = result;
			return *this;
		}

		static Matrix4x4<T>& perspective(T fov, T aspectRatio, T zNear, T zFar) { //TODO testing
			T tanHalfFov = (T)tan(fov / 2);

			Matrix4x4<T> result{ };
			result.row1.x = 1 / (aspectRatio * tanHalfFov);
			result.row2.y = 1 / (tanHalfFov);
			result.row3.z = -(zFar + zNear) / (zFar - zNear);
			result.row3.w = -1;
			result.row4.z = -(2 * zFar * zNear) / (zFar - zNear);
			return result;
		}
	};

	// <<
	template<typename T>
	inline std::ostream& operator<<(std::ostream& os, const Matrix4x4<T>& matrix) {
		return (os << matrix.row1 << '\n' << matrix.row2 << '\n' << matrix.row3 << '\n' << matrix.row4);
	}

	// *
	template<typename T>
	inline Matrix4x4<T> operator*(const Matrix4x4<T>& mat1, const Matrix4x4<T>& mat2) {
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
			mat1.row4.x * mat2.row1.w + mat1.row4.y * mat2.row2.w + mat1.row4.z * mat2.row3.w + mat1.row4.w * mat2.row4.w
		);
	}
	
	template<typename T>
	inline Vector4<T> operator*(const Vector4<T>& vec, const Matrix4x4<T>& mat) {
		return Vector4<T>(
			// X
			vec.x * mat.row1.x + vec.y * mat.row2.x + vec.z * mat.row3.x + vec.w * mat.row4.x,
			// Y
			vec.x * mat.row1.y + vec.y * mat.row2.y + vec.z * mat.row3.y + vec.w * mat.row4.y,
			// Z
			vec.x * mat.row1.z + vec.y * mat.row2.z + vec.z * mat.row3.z + vec.w * mat.row4.z,
			// W
			vec.x * mat.row1.w + vec.y * mat.row2.w + vec.z * mat.row3.w + vec.w * mat.row4.w
		);
	}
}