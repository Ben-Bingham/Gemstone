#pragma once

#include <ostream>
#include <string>

namespace Malachite {
	template<typename T>
	class Vector2 {
	public:
		Vector2() {}
		Vector2(T X, T Y) : x(X), y(Y) {}
		Vector2(T val) : x(val), y(val) {}

		T x{ };
		T y{ };

		// Negation
		Vector2<T> operator-() const {
			return Vector2<T>{ -x, -y };
		}

		// +=
		Vector2<T>& operator+=(const Vector2<T>& other) {
			this->x += other.x;
			this->y += other.y;
			return *this;
		}

		Vector2<T>& operator+=(const T& scaler) {
			this->x += scaler;
			this->y += scaler;
			return *this;
		}

		// -=
		Vector2<T>& operator-=(const Vector2<T>& other) {
			this->x -= other.x;
			this->y -= other.y;
			return *this;
		}

		Vector2<T>& operator-=(const T& scaler) {
			this->x -= scaler;
			this->y -= scaler;
			return *this;
		}

		// *=
		Vector2<T>& operator*=(const Vector2<T>& other) {
			this->x *= other.x;
			this->y *= other.y;
			return *this;
		}

		Vector2<T>& operator*=(const T& scaler) {
			this->x *= scaler;
			this->y *= scaler;
			return *this;
		}

		// /=
		Vector2<T>& operator/=(const Vector2<T>& other) {
			this->x /= other.x;
			this->y /= other.y;
			return *this;
		}

		Vector2<T>& operator/=(const T& scaler) {
			this->x /= scaler;
			this->y /= scaler;
			return *this;
		}

		// Comparison
		bool operator==(const Vector2<T> other) const {
			return x == other.x && y == other.y;
		}

		bool operator!=(const Vector2<T> other) const {
			return !operator==(other);
		}

		// Utility
		T length() const {
			return (T)sqrt(x * x + y * y);
		}

		Vector2<T> normalize() {
			Vector2<T> result{ *this };
			T inverseLength = (T)1 / this->length();
			result *= inverseLength;
			return result;
		}

		std::string toString() {
			return std::string{ "X: " + std::to_string(x) + ", Y: " + std::to_string(y) };
		}
	};

	// <<
	template<typename T>
	inline std::ostream& operator<<(std::ostream& os, const Vector2<T>& vector) {
		return (os << "X: " << vector.x << " Y: " << vector.y);
	}

	// +
	template<typename T>
	inline Vector2<T> operator+(const Vector2<T>& vec1, const Vector2<T>& vec2) {
		return Vector2<T>(vec1.x + vec2.x, vec1.y + vec2.y);
	}

	template<typename T>
	inline Vector2<T> operator+(const Vector2<T>& vec, const T& scaler) {
		return Vector2<T>(vec.x + scaler, vec.y + scaler);
	}

	// -
	template<typename T>
	inline Vector2<T> operator-(const Vector2<T>& vec1, const Vector2<T>& vec2) {
		return Vector2<T>(vec1.x - vec2.x, vec1.y - vec2.y);
	}

	template<typename T>
	inline Vector2<T> operator-(const Vector2<T>& vec, const T& scaler) {
		return Vector2<T>(vec.x - scaler, vec.y - scaler);
	}

	// *
	template<typename T>
	inline Vector2<T> operator*(const Vector2<T>& vec1, const Vector2<T>& vec2) {
		return Vector2<T>(vec1.x * vec2.x, vec1.y * vec2.y);
	}

	template<typename T>
	inline Vector2<T> operator*(const Vector2<T>& vec, const T& scaler) {
		return Vector2<T>(vec.x * scaler, vec.y * scaler);
	}

	template<typename T>
	inline Vector2<T> operator*(const T& scaler, const Vector2<T>& vec) {
		return vec * scaler;
	}

	// /
	template<typename T>
	inline Vector2<T> operator/(const Vector2<T>& vec1, const Vector2<T>& vec2) {
		return Vector2<T>(vec1.x / vec2.x, vec1.y / vec2.y);
	}

	template<typename T>
	inline Vector2<T> operator/(const Vector2<T>& vec, const T& scaler) {
		return Vector2<T>(vec.x / scaler, vec.y / scaler);
	}

	// Dot
	template<typename T>
	T dot(const Vector2<T>& vec1, const Vector2<T>& vec2) {
		return vec1.x * vec2.x + vec1.y * vec2.y;
	}
}