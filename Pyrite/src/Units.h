#pragma once

#include "Vector.h"

namespace Pyrite {
	using Kilogram = float;
	using Meter = float;
	using Position3D = Malachite::Vector3<Meter>;
	using Second = float;
	using GravitationalField = float;
	using Newton = float;
	using Newton3D = Malachite::Vector3<Newton>;
	using Speed = float;
	using Velocity = Malachite::Vector3<Speed>;
	using Displacement = Malachite::Vector3<Meter>;
	using Acceleration = float;
	using Acceleration3D = Malachite::Vector3<Acceleration>;

	namespace Literals {
		// Mass
		inline Kilogram operator ""_kg(long double x) { return (Kilogram)x; }
		inline Kilogram operator ""_g(long double x) { return (Kilogram)x / 1000; }

		// Distance
		inline Meter operator ""_km(long double x) { return (Meter)x * 1000; 	}
		inline Meter operator ""_m(long double x) { return (Meter)x; 	}
		inline Meter operator ""_cm(long double x) { return (Meter)x / 100; }
		inline Meter operator ""_mm(long double x) { return (Meter)x / 1000; }

		// Time
		inline Second operator ""_ms(long double x) { return (Second)x / 1000; }
		inline Second operator ""_s(long double x) { return (Second)x; }
		inline Second operator ""_min(long double x) { return (Second)x * 60; }
		inline Second operator ""_hr(long double x) { return (Second)x * 3600; }
		inline Second operator ""_day(long double x) { return (Second)x * 3600 * 24; }

		// Grav Fields
		inline GravitationalField operator ""_gField (long double x) { return (GravitationalField)x; }

		// Force
		inline Newton operator ""_N(long double x) { return (Newton)x; }
	}
}