#pragma once

#include "Vector.h"

namespace Ruby {
	class Colour {
	public:
		Colour();
		Colour(float value);
		Colour(Malachite::Vector4f colour);
		Colour(Malachite::Vector3f colour, float alpha = 1.0f);
		explicit Colour(float r, float g, float b, float a = 1.0f);
		explicit Colour(int r, int g, int b, int a = 255);

		Malachite::Vector4f colour;

		[[nodiscard]] Malachite::Vector3f toVec3() const;
		[[nodiscard]] Malachite::Vector4uc toVec4() const;

		bool operator==(const Colour& other) const;
		bool operator!=(const Colour& other) const;

		const static Colour red;
		const static Colour blue;
		const static Colour green;
		const static Colour pink;
		const static Colour orange;
		const static Colour yellow;
		const static Colour purple;
		const static Colour white;
		const static Colour black;

	private:
		static Malachite::Vector4f initWith0To255(int r, int g, int b, int a);
	};
}