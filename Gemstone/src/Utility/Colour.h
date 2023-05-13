#pragma once
#include "Math/Vector.h"

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


		[[nodiscard]] Vector4f ToVec4f() const;

		using Vector4uc::operator==;
		using Vector4uc::operator!=;


		const static Colour RED;
		const static Colour BLUE;
		const static Colour GREEN;
		const static Colour MAGENTA;
		const static Colour YELLOW;
		const static Colour CYAN;
		const static Colour WHITE;
		const static Colour BLACK;
		const static Colour ORANGE;
		const static Colour PINK;
		const static Colour LIME_GREEN;
		const static Colour LIGHT_GREEN;
		const static Colour PURPLE;
		const static Colour LIGHT_BLUE;
	};
}