#pragma once

#include <ostream>
#include <cassert>

namespace Malachite {
	template<typename T>
	class Vector4 {
	public:
		Vector4() {}
		Vector4(T X, T Y, T Z, T W) : x(X), y(Y), z(Z), w(W) {}
		Vector4(T val) : x(val), y(val), z(val), w(val) {}
		Vector4(Vector3<T> vector3, T W) : x(vector3.x), y(vector3.y), z(vector3.z), w(W) {}

		T x{ };
		T y{ };
		T z{ };
		T w{ };

		T operator[](int index) const {
#ifdef MALACHITE_DEBUG
			assert(index < 4);
#endif // MALACHITE_DEBUG
			switch (index) {
			case 0:
				return x;
			case 1:
				return y;
			case 2:
				return z;
			case 3:
				return w;
			default: return (T)0;
			}
		}

		// Negation
		Vector4<T> operator-() const {
			return Vector4<T>{ -x, -y, -z, -w };
		}

		// +=
		Vector4<T>& operator+=(const Vector4<T>& other) {
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
			this->w += other.w;
			return *this;
		}

		Vector4<T>& operator+=(const T& scaler) {
			this->x += scaler;
			this->y += scaler;
			this->z += scaler;
			this->w += scaler;
			return *this;
		}

		// -=
		Vector4<T>& operator-=(const Vector4<T>& other) {
			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;
			this->w -= other.w;
			return *this;
		}

		Vector4<T>& operator-=(const T& scaler) {
			this->x -= scaler;
			this->y -= scaler;
			this->z -= scaler;
			this->w -= scaler;
			return *this;
		}

		// *=
		Vector4<T>& operator*=(const Vector4<T>& other) {
			this->x *= other.x;
			this->y *= other.y;
			this->z *= other.z;
			this->w *= other.w;
			return *this;
		}

		Vector4<T>& operator*=(const T& scaler) {
			this->x *= scaler;
			this->y *= scaler;
			this->z *= scaler;
			this->w *= scaler;
			return *this;
		}

		// /=
		Vector4<T>& operator/=(const Vector4<T>& other) {
			this->x /= other.x;
			this->y /= other.y;
			this->z /= other.z;
			this->w /= other.w;
			return *this;
		}

		Vector4<T>& operator/=(const T& scaler) {
			this->x /= scaler;
			this->y /= scaler;
			this->z /= scaler;
			this->w /= scaler;
			return *this;
		}

		// Comparison
		bool operator==(const Vector4<T> other) const {
			return x == other.x && y == other.y && z == other.z && w == other.w;
		}

		bool operator!=(const Vector4<T> other) const {
			return !operator==(other);
		}

		// Utility
		T length() const {
			return (T)sqrt(x * x + y * y + z * z + w * w);
		}

		Vector4<T> normalize() {
			Vector4<T> result{ *this };
			T inverseLength = (T)1 / this->length();
			result *= inverseLength;
			return result;
		}

		std::string toString() const {
			return std::string{ "X: " + std::to_string(x) + ", Y: " + std::to_string(y) + ", Z: " + std::to_string(z) + ", W: " + std::to_string(w)};
		}
	};

	// <<
	template<typename T>
	inline std::ostream& operator<<(std::ostream& os, const Vector4<T>& vector) {
		return (os << "X: " << vector.x << " Y: " << vector.y << " Z: " << vector.z << " W: " << vector.w);
	}

	// +
	template<typename T>
	inline Vector4<T> operator+(const Vector4<T>& vec1, const Vector4<T>& vec2) {
		return Vector4<T>(vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z, vec1.w + vec2.w);
	}

	template<typename T>
	inline Vector4<T> operator+(const Vector4<T>& vec, const T& scaler) {
		return Vector4<T>(vec.x + scaler, vec.y + scaler, vec.z + scaler, vec.w + scaler);
	}

	// -
	template<typename T>
	inline Vector4<T> operator-(const Vector4<T>& vec1, const Vector4<T>& vec2) {
		return Vector4<T>(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z, vec1.w - vec2.w);
	}

	template<typename T>
	inline Vector4<T> operator-(const Vector4<T>& vec, const T& scaler) {
		return Vector4<T>(vec.x - scaler, vec.y - scaler, vec.z - scaler, vec.w - scaler);
	}

	// *
	template<typename T>
	inline Vector4<T> operator*(const Vector4<T>& vec1, const Vector4<T>& vec2) {
		return Vector4<T>(vec1.x * vec2.x, vec1.y * vec2.y, vec1.z * vec2.z, vec1.w * vec2.w);
	}

	template<typename T>
	inline Vector4<T> operator*(const Vector4<T>& vec, const T& scaler) {
		return Vector4<T>(vec.x * scaler, vec.y * scaler, vec.z * scaler, vec.w * scaler);
	}

	template<typename T>
	inline Vector4<T> operator*(const T& scaler, const Vector4<T>& vec) {
		return vec * scaler;
	}

	// /
	template<typename T>
	inline Vector4<T> operator/(const Vector4<T>& vec1, const Vector4<T>& vec2) {
		return Vector4<T>(vec1.x / vec2.x, vec1.y / vec2.y, vec1.z / vec2.z, vec1.w / vec2.w);
	}

	template<typename T>
	inline Vector4<T> operator/(const Vector4<T>& vec, const T& scaler) {
		return Vector4<T>(vec.x / scaler, vec.y / scaler, vec.z / scaler, vec.w / scaler);
	}

	// Dot
	template<typename T>
	T dot(const Vector4<T>& vec1, const Vector4<T>& vec2) {
		return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z + vec1.w * vec2.w;
	}
}