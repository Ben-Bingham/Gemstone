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

	namespace Literals { //TODO add versions for non floating point values ie: 10_kg
		// Mass
		inline Kilogram operator ""_kg(long double x);
		inline Kilogram operator ""_kg(unsigned long long int x);
		inline Kilogram operator ""_g(long double x);
		inline Kilogram operator ""_g(unsigned long long int x);

		// Distance
		inline Meter operator ""_km(long double x);
		inline Meter operator ""_km(unsigned long long int x);
		inline Meter operator ""_m(long double x);
		inline Meter operator ""_m(unsigned long long int x);
		inline Meter operator ""_cm(long double x);
		inline Meter operator ""_cm(unsigned long long int x);
		inline Meter operator ""_mm(long double x);
		inline Meter operator ""_mm(unsigned long long int x);

		// Time
		inline Second operator ""_ms(long double x);
		inline Second operator ""_ms(unsigned long long int x);
		inline Second operator ""_s(long double x);
		inline Second operator ""_s(unsigned long long int x);
		inline Second operator ""_min(long double x);
		inline Second operator ""_min(unsigned long long int x);
		inline Second operator ""_hr(long double x);
		inline Second operator ""_hr(unsigned long long int x);
		inline Second operator ""_day(long double x);
		inline Second operator ""_day(unsigned long long int x);

		// Force
		inline Newton operator ""_N(long double x);
		inline Newton operator ""_N(unsigned long long int x);

		// Speed
		inline Speed operator ""_mPerS(long double x);
		inline Speed operator ""_mPerS(unsigned long long int x);
	}
}