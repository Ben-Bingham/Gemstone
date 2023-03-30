#pragma once
#include "Math/Vector.h"

namespace Gem {
	class Colour {
	public:
		Colour();
		Colour(float value);
		Colour(Vector4f colour);
		Colour(Vector3f colour, float alpha = 1.0f);
		explicit Colour(float r, float g, float b, float a = 1.0f);
		explicit Colour(int r, int g, int b, int a = 255);

		Vector4f colour;

		[[nodiscard]] Vector3f toVec3() const;
		[[nodiscard]] Vector4uc toVec4() const;

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
		static Vector4f initWith0To255(int r, int g, int b, int a);
	};
}