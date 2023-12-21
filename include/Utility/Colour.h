#pragma once
#include "Math/Vector.h"
#include "Gem.h"

namespace Gem {
	class Colour : Vector4uc {
	public:
		Colour() = default;
		Colour(const Colour& other) = default;
		Colour(Colour&& other) noexcept = default;
		Colour& operator=(const Colour& other) = default;
		Colour& operator=(Colour&& other) noexcept = default;
		explicit Colour(int colour);
		explicit Colour(int red, int green, int blue, int alpha = 255);

		using Vector4uc::r;
		using Vector4uc::g;
		using Vector4uc::b;
		using Vector4uc::a;

		unsigned char* Data();

		[[nodiscard]] Vector4f ToVec4f() const;

		using Vector4uc::operator==;
		using Vector4uc::operator!=;

		const static Colour Red;
		const static Colour Blue;
		const static Colour Green;
		const static Colour Magenta;
		const static Colour Yellow;
		const static Colour Cyan;
		const static Colour White;
		const static Colour Black;
		const static Colour Orange;
		const static Colour Pink;
		const static Colour LimeGreen;
		const static Colour LightGreen;
		const static Colour Purple;
		const static Colour LightBlue;
	};
}