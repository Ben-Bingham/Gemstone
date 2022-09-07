#pragma once

namespace Malachite {
	template<typename T>
	class Vector2 {
	public:
		Vector2() {}
		Vector2(T X, T Y) : x(X), y(Y) {}
		Vector2(T val) : x(val), y(val) {}

		T x{ };
		T y{ };

		Vector2<T>& operator-() {
			return Vector2<T>{ -this->x, -this->y };
		}

		Vector2<T>& operator+=(Vector2<T> other) {
			this->x += other.x;
			this->y += other.y;
			return *this;
		}

		Vector2<T>& operator-=(Vector2<T> other) {
			this->operator+=(-other);
			return *this;
		}

		Vector2<T>& operator*=(Vector2<T> other) {
			this->x *= other.x;
			this->y *= other.y;
			return *this;
		}

		Vector2<T>& operator/=(Vector2<T> other) {
			this->operator*=(1 / other);
			return *this;
		}
	};
}