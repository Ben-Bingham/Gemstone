#pragma once



namespace Pyrite {
	namespace Literals {
		inline long double operator""_b(long double x) { return x; }
	}

	long double mass = 4.0_b;


	using Kilogram = float;
	//inline Kilogram operator "" kg(long double) {}


	using Meter = float;
	using Second = float;
}