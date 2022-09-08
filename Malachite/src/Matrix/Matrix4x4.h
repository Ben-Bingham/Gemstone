#pragma once
#include <initializer_list>

#include "vector/Vector.h"

namespace Malachite {
	template<typename T>
	class Matrix4x4 {
	public:
		Matrix4x4() {}
		Matrix4x4(T val) : row1(val), row2(val), row3(val), row4(val) {}
		Matrix4x4(Vector4<T> Row1, Vector4<T> Row2, Vector4<T> Row3, Vector4<T> Row4) : row1(Row1), row2(Row2), row3(Row3), row4(Row4) {}
		Matrix4x4(std::initializer_list<T> initList) {
			if (initList.size())
		}

		Vector4<T> row1{ };
		Vector4<T> row2{ };
		Vector4<T> row3{ };
		Vector4<T> row4{ };
	};
}