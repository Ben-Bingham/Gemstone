#include "Vector.h"

namespace Malachite {
	template class Vector2<float>;
	template class Vector2<double>;
	template class Vector2<int>;

	template class Vector3<float>;
	template class Vector3<double>;
	template class Vector3<int>;

	template class Vector4<float>;
	template class Vector4<double>;
	template class Vector4<int>;

	template<typename T>
	const Vector3<T> Vector3<T>::up{ static_cast<T>(0), static_cast<T>(1), static_cast<T>(0) };
	template<typename T>
	const Vector3<T> Vector3<T>::down{ static_cast<T>(0), static_cast<T>(-1), static_cast<T>(0) };
	template<typename T>
	const Vector3<T> Vector3<T>::north{ static_cast<T>(0), static_cast<T>(0), static_cast<T>(-1) };
	template<typename T>
	const Vector3<T> Vector3<T>::south{ static_cast<T>(0), static_cast<T>(0), static_cast<T>(1) };
	template<typename T>
	const Vector3<T> Vector3<T>::east{ static_cast<T>(1), static_cast<T>(0), static_cast<T>(0) };
	template<typename T>
	const Vector3<T> Vector3<T>::west{ static_cast<T>(-1), static_cast<T>(0), static_cast<T>(0) };
	template<typename T>
	const Vector3<T> Vector3<T>::zero{ static_cast<T>(0), static_cast<T>(0), static_cast<T>(0) };
}