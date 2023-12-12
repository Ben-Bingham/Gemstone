#include "pch.h"
#include "Utility/Colour.h"

namespace Gem {
	Colour::Colour(const int colour)
		: Vector4uc((unsigned char)colour) {
		
	}

	Colour::Colour(const int red, const int green, const int blue, const int alpha)
		: Vector4uc((unsigned char)red, (unsigned char)green, (unsigned char)blue, (unsigned char)alpha){
		
	}

	unsigned char* Colour::Data() {
		return &r;
	}

	Vector4f Colour::ToVec4f() const {
		return Vector4f{ (float)r / 255.0f, (float)g / 255.0f, (float)b / 255.0f, (float)a / 255.0f };
	}

	const Colour Colour::RED		{ 255,   0,   0 };
	const Colour Colour::BLUE		{   0,   0, 255 };
	const Colour Colour::GREEN		{   0, 255,   0 };
	const Colour Colour::MAGENTA	{ 255,   0, 255 };
	const Colour Colour::YELLOW		{ 255, 255,   0 };
	const Colour Colour::CYAN		{   0, 255, 255 };
	const Colour Colour::WHITE		{ 255, 255, 255 };
	const Colour Colour::BLACK		{   0,   0,   0 };
	const Colour Colour::ORANGE		{ 255, 128,   0 };
	const Colour Colour::PINK		{ 255,   0, 128 };
	const Colour Colour::LIME_GREEN { 128, 255,   0 };
	const Colour Colour::LIGHT_GREEN{   0, 255,      128 };
	const Colour Colour::PURPLE		{ 128,   0, 255 };
	const Colour Colour::LIGHT_BLUE {   0, 128, 255 };
}