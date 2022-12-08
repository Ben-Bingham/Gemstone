#pragma once
#include "Matrix4x4.h"

namespace Malachite {
	template<typename T>
	Matrix4x4<T> lookAt(const Vector3<T>& eye, const Vector3<T>& target, const Vector3<T>& up) {
		Vector3<T> direction((target - eye).normalize());
		Vector3<T> s((cross(direction, up)).normalize());
		Vector3<T> relativeUp(cross(s, direction));

		Matrix4x4<T> result{ 1.0f };
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
		return result;
	}

	template<typename T>
	Matrix4x4<T> perspective(T fov, T aspectRatio, T zNear, T zFar) {
		T tanHalfFov = (T)tan(fov / 2);

		Matrix4x4<T> result{ };
		result.row1.x = 1 / (aspectRatio * tanHalfFov);
		result.row2.y = 1 / (tanHalfFov);
		result.row3.z = -(zFar + zNear) / (zFar - zNear);
		result.row3.w = -1;
		result.row4.z = -(2 * zFar * zNear) / (zFar - zNear);
		return result;
	}

	template<typename T>
	Matrix4x4<T> ortho(T left, T right, T bottom, T top, T zNear, T zFar) {
		Matrix4x4<T> result{ 1.0f };
		result.row1.x = 2 / (right - left);
		result.row2.y = 2 / (top - bottom);
		result.row3.z = -2 / (zFar - zNear);
		result.row4.x = -(right + left) / (right - left);
		result.row4.y = -(top + bottom) / (top - bottom);
		result.row4.z = -(zFar + zNear) / (zFar - zNear);
		return result;
	}
}