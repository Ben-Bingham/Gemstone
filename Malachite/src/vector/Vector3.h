#pragma once

#include <ostream>
#include <string>

namespace Malachite {
	template<typename T>
	class Vector3 { //TODO make some default values like up or down or 0;
	public:
		Vector3() {}
		Vector3(T X, T Y, T Z) : x(X), y(Y), z(Z) {}
		Vector3(T val) : x(val), y(val), z(val) {}

		T x{ };
		T y{ };
		T z{ };

		// Negation
		Vector3<T> operator-() const {
			return Vector3<T>{ -x, -y, -z };
		}

		// +=
		Vector3<T>& operator+=(const Vector3<T>& other) {
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
			return *this;
		}

		Vector3<T>& operator+=(const T& scaler) {
			this->x += scaler;
			this->y += scaler;
			this->z += scaler;
			return *this;
		}

		// -=
		Vector3<T>& operator-=(const Vector3<T>& other) {
			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;
			return *this;
		}

		Vector3<T>& operator-=(const T& scaler) {
			this->x -= scaler;
			this->y -= scaler;
			this->z -= scaler;
			return *this;
		}

		// *=
		Vector3<T>& operator*=(const Vector3<T>& other) {
			this->x *= other.x;
			this->y *= other.y;
			this->z *= other.z;
			return *this;
		}

		Vector3<T>& operator*=(const T& scaler) {
			this->x *= scaler;
			this->y *= scaler;
			this->z *= scaler;
			return *this;
		}

		// /=
		Vector3<T>& operator/=(const Vector3<T>& other) {
			this->x /= other.x;
			this->y /= other.y;
			this->z /= other.z;
			return *this;
		}

		Vector3<T>& operator/=(const T& scaler) {
			this->x /= scaler;
			this->y /= scaler;
			this->z /= scaler;
			return *this;
		}

		// Comparison
		bool operator==(const Vector3<T> other) const {
			return x == other.x && y == other.y && z == other.z;
		}

		bool operator!=(const Vector3<T> other) const {
			return !operator==(other);
		}

		// Utility
		T length() const {
			return (T)sqrt(x * x + y * y + z * z);
		}

		Vector3<T> normalize() {
			Vector3<T> result{ *this };
			T inverseLength = (T)1 / this->length();
			result *= inverseLength;
			return result;
		}

		std::string toString() {
			return std::string{ "X: " + std::to_string(x) + ", Y: " + std::to_string(y) + ", Z: " + std::to_string(z) };
		}
	};

	// <<
	template<typename T>
	inline std::ostream& operator<<(std::ostream& os, const Vector3<T>& vector) {
		return (os << "X: " << vector.x << " Y: " << vector.y << " Z: " << vector.z);
	}

	// +
	template<typename T>
	inline Vector3<T> operator+(const Vector3<T>& vec1, const Vector3<T>& vec2) {
		return Vector3<T>(vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z);
	}

	template<typename T>
	inline Vector3<T> operator+(const Vector3<T>& vec, const T& scaler) {
		return Vector3<T>(vec.x + scaler, vec.y + scaler, vec.z + scaler);
	}

	// -
	template<typename T>
	inline Vector3<T> operator-(const Vector3<T>& vec1, const Vector3<T>& vec2) {
		return Vector3<T>(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z);
	}

	template<typename T>
	inline Vector3<T> operator-(const Vector3<T>& vec, const T& scaler) {
		return Vector3<T>(vec.x - scaler, vec.y - scaler, vec.z - scaler);
	}

	// *
	template<typename T>
	inline Vector3<T> operator*(const Vector3<T>& vec1, const Vector3<T>& vec2) {
		return Vector3<T>(vec1.x * vec2.x, vec1.y * vec2.y, vec1.z * vec2.z);
	}

	template<typename T>
	inline Vector3<T> operator*(const Vector3<T>& vec, const T& scaler) {
		return Vector3<T>(vec.x * scaler, vec.y * scaler, vec.z * scaler);
	}

	template<typename T>
	inline Vector3<T> operator*(const T& scaler, const Vector3<T>& vec) {
		return vec * scaler;
	}

	// /
	template<typename T>
	inline Vector3<T> operator/(const Vector3<T>& vec1, const Vector3<T>& vec2) {
		return Vector3<T>(vec1.x / vec2.x, vec1.y / vec2.y, vec1.z / vec2.z);
	}

	template<typename T>
	inline Vector3<T> operator/(const Vector3<T>& vec, const T& scaler) {
		return Vector3<T>(vec.x / scaler, vec.y / scaler, vec.z / scaler);
	}

	// Dot
	template<typename T>
	T dot(const Vector3<T>& vec1, const Vector3<T>& vec2) {
		return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
	}

	// Cross
	template<typename T>
	Vector3<T> cross(const Vector3<T>& vec1, const Vector3<T>& vec2) {
		return Vector3<T>{ vec1.y * vec2.z - vec1.z * vec2.y, vec1.z * vec2.x - vec1.x * vec2.z, vec1.x * vec2.y - vec1.y * vec2.x };
	}
}