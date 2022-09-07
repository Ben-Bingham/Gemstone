#include <ostream>

#include "Vector.h"

namespace Malachite {
	// Vector2f
	template<typename T>
	std::ostream& operator<<(std::ostream& os, const Vector2<T>& vector) {
		return (os << "X:" << vector.x << "Y: " << vector.y);
	}

	/*std::ostream& operator<<(std::ostream& os, const Vector2d& vector) {
		return (os << "X:" << vector.x << "Y: " << vector.y);
	}

	std::ostream& operator<<(std::ostream& os, const Vector2i& vector) {
		return (os << "X:" << vector.x << "Y: " << vector.y);
	}

	std::ostream& operator<<(std::ostream& os, const Vector2ui& vector) {
		return (os << "X:" << vector.x << "Y: " << vector.y);
	}*/
}