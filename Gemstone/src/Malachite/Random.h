#pragma once
#include <cstdlib>

namespace Malachite {
	template<typename T>
	T random() { // [0, 1[
		return std::rand() / (RAND_MAX + static_cast<T>(1));
	}

	template<typename T>
	T random(T min, T max) { // [min, max[
		return min + (max - min) * random<T>();
	}

	template<typename T>
	Vector3<T> random(Vector3<T> min, Vector3<T> max) { // [min, max[
		Vector3<T> result;
		result.x = min.x + (max.x - min.x) * random<T>();
		result.y = min.y + (max.y - min.y) * random<T>();
		result.z = min.z + (max.z - min.z) * random<T>();
		return result;
	}

	template<typename T>
	Vector3<T> randomInUnitSphere() {
		while(true) {
			Malachite::Vector3<T> vector = random((T)-1, (T)1);
			if (vector.lengthSquared() >= 1) continue;
			return vector;
		}
	}

	template<typename T>
	Vector4<T> random(Vector4<T> min, Vector4<T> max) { // [min, max[
		Vector4<T> result;
		result.x = min.x + (max.x - min.x) * random<T>();
		result.y = min.y + (max.y - min.y) * random<T>();
		result.z = min.z + (max.z - min.z) * random<T>();
		result.w = min.w + (max.w - min.w) * random<T>();
		return result;
	}
}