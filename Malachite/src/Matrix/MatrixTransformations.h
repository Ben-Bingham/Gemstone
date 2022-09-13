#pragma once
#include "Matrix4x4.h"

namespace Malachite {
	template<typename T>
	Matrix4x4<T> lookAt(const Vector3<T>& eye, const Vector3<T>& target, const Vector3<T>& up) { //TODO testing
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
		return result; //Might not work returning local variable
	}

	template<typename T>
	Matrix4x4<T> perspective(T fov, T aspectRatio, T zNear, T zFar) { //TODO testing
		T tanHalfFov = (T)tan(fov / 2);

		Matrix4x4<T> result{ };
		result.row1.x = 1 / (aspectRatio * tanHalfFov);
		result.row2.y = 1 / (tanHalfFov);
		result.row3.z = -(zFar + zNear) / (zFar - zNear);
		result.row3.w = -1;
		result.row4.z = -(2 * zFar * zNear) / (zFar - zNear);
		return result; //Might not work returning local variable
	}
}