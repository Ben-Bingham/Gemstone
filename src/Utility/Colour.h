#pragma once
#include "Gem.h"

namespace Gem {
	class Colour : glm::ivec4 {
	public:
		Colour() = default;
		Colour(const Colour& other) = default;
		Colour(Colour&& other) noexcept = default;
		Colour& operator=(const Colour& other) = default;
		Colour& operator=(Colour&& other) noexcept = default;
		explicit Colour(int colour);
		explicit Colour(int red, int green, int blue, int alpha = 255);

		using glm::ivec4::r;
		using glm::ivec4::g;
		using glm::ivec4::b;
		using glm::ivec4::a;

		unsigned char* Data();

		[[nodiscard]] glm::vec4 ToVec4f() const;

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