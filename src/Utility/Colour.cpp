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

	const Colour Colour::Red		{ 255,   0,   0 };
	const Colour Colour::Blue		{   0,   0, 255 };
	const Colour Colour::Green		{   0, 255,   0 };
	const Colour Colour::Magenta	{ 255,   0, 255 };
	const Colour Colour::Yellow		{ 255, 255,   0 };
	const Colour Colour::Cyan		{   0, 255, 255 };
	const Colour Colour::White		{ 255, 255, 255 };
	const Colour Colour::Black		{   0,   0,   0 };
	const Colour Colour::Orange		{ 255, 128,   0 };
	const Colour Colour::Pink		{ 255,   0, 128 };
	const Colour Colour::LimeGreen { 128, 255,   0 };
	const Colour Colour::LightGreen{   0, 255,      128 };
	const Colour Colour::Purple		{ 128,   0, 255 };
	const Colour Colour::LightBlue {   0, 128, 255 };
}