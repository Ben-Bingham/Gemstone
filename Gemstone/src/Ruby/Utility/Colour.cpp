#include "Colour.h"

namespace Ruby {
	Colour::Colour()
		: colour(0.0f, 0.0f, 0.0f, 1.0f) {}
	Colour::Colour(const float value)
		: colour(value, value, value, value) {}
	Colour::Colour(const Malachite::Vector4f colour)
		: colour(colour) {}
	Colour::Colour(Malachite::Vector3f colour, float alpha)
		: colour(colour.x, colour.y, colour.z, alpha) {}
	Colour::Colour(const float r, const float g, const float b, const float a)
		: colour(r, g, b, a) {}
	Colour::Colour(const int r, const int g, const int b, const int a)
		: colour(initWith0To255(r, g, b, a)) {}

	Malachite::Vector3f Colour::toVec3() const { return Malachite::Vector3f{colour.x, colour.y, colour.z}; }
	Malachite::Vector4uc Colour::toVec4() const {
		return Malachite::Vector4uc{
			static_cast<unsigned char>(colour.x * 255),
			static_cast<unsigned char>(colour.y * 255),
			static_cast<unsigned char>(colour.z * 255),
			static_cast<unsigned char>(colour.w * 255)
		};
	}

	bool Colour::operator==(const Colour& other) const {
		return colour == other.colour;
	}

	bool Colour::operator!=(const Colour& other) const {
		return !operator==(other);
	}

	Malachite::Vector4f Colour::initWith0To255(const int r, const int g, const int b, const int a) {
		constexpr float oneOverTwoFiftyFive = 1.0f / 255.0f;
		float x, y, z, w;
		if (r != 255) {
			x = oneOverTwoFiftyFive * static_cast<float>(r % 255);
		}
		else {
			x = 1.0f;
		}

		if (g != 255) {
			y = oneOverTwoFiftyFive * static_cast<float>(g % 255);
		}
		else {
			y = 1.0f;
		}

		if (b != 255) {
			z = oneOverTwoFiftyFive * static_cast<float>(b % 255);
		}
		else {
			z = 1.0f;
		}

		if (a != 255) {
			w = oneOverTwoFiftyFive * static_cast<float>(a % 255);
		}
		else {
			w = 1.0f;
		}

		return Malachite::Vector4f{x, y, z, w};
	}

	const Colour Colour::red{255, 0, 0};
	const Colour Colour::blue{0, 0, 255};
	const Colour Colour::green{0, 255, 0};
	const Colour Colour::pink{255, 0, 255};
	const Colour Colour::orange{255, 128, 0};
	const Colour Colour::yellow{255, 255, 0};
	const Colour Colour::purple{255, 0, 255};
	const Colour Colour::white{255, 255, 255};
	const Colour Colour::black{0, 0, 0};
}