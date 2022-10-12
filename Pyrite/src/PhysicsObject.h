#pragma once

namespace Pyrite {
	using Kilogram = float;
	//inline Kilogram operator "" kg(long double) {}

	Kilogram operator "" _b(long double x) { return x; }


	using Meter = float;
	using Second = float;
}