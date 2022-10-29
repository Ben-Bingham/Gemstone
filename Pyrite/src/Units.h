#pragma once

#include "Vector.h"

namespace Pyrite {
	using Kilogram = float;
	using Meter = float;
	using Point3D = Malachite::Vector3<Meter>;
	using Point2D = Malachite::Vector2<Meter>;
	using Second = float;
	using Newton = float;
	using Newton3D = Malachite::Vector3<Newton>;
	using Speed = float;
	using Velocity = Malachite::Vector3<Speed>;
	using Displacement = Malachite::Vector3<Meter>;
	using Direction = Malachite::Vector3<Meter>;
	using Acceleration = float;
	using Acceleration3D = Malachite::Vector3<Acceleration>;
	using KilogramMeterPerSeconds = float;

	namespace Literals {
		// Mass
		Kilogram operator ""_kg(long double x);
		Kilogram operator ""_kg(unsigned long long int x);
		Kilogram operator ""_g(long double x);
		Kilogram operator ""_g(unsigned long long int x);

		// Distance
		Meter operator ""_km(long double x);
		Meter operator ""_km(unsigned long long int x);
		Meter operator ""_m(long double x);
		Meter operator ""_m(unsigned long long int x);
		Meter operator ""_cm(long double x);
		Meter operator ""_cm(unsigned long long int x);
		Meter operator ""_mm(long double x);
		Meter operator ""_mm(unsigned long long int x);

		// Time
		Second operator ""_ms(long double x);
		Second operator ""_ms(unsigned long long int x);
		Second operator ""_s(long double x);
		Second operator ""_s(unsigned long long int x);
		Second operator ""_min(long double x);
		Second operator ""_min(unsigned long long int x);
		Second operator ""_hr(long double x);
		Second operator ""_hr(unsigned long long int x);
		Second operator ""_day(long double x);
		Second operator ""_day(unsigned long long int x);

		// Force
		Newton operator ""_N(long double x);
		Newton operator ""_N(unsigned long long int x);

		// Speed
		Speed operator ""_mPerS(long double x);
		Speed operator ""_mPerS(unsigned long long int x);
	}
}