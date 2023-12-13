#include "Units.h"

namespace Pyrite {
	namespace Literals {
		// Mass
		Kilogram operator ""_kg(long double x) { return (Kilogram)x; }
		Kilogram operator ""_kg(unsigned long long int x) { return (Kilogram)x; }
		Kilogram operator ""_g(long double x) { return (Kilogram)x / 1000; }
		Kilogram operator ""_g(unsigned long long int x) { return (Kilogram)x / 1000; }

		// Distance
		Meter operator ""_km(long double x) { return (Meter)x * 1000; }
		Meter operator ""_km(unsigned long long int x) { return (Meter)x * 1000; }
		Meter operator ""_m(long double x) { return (Meter)x; }
		Meter operator ""_m(unsigned long long int x) { return (Meter)x; }
		Meter operator ""_cm(long double x) { return (Meter)x / 100; }
		Meter operator ""_cm(unsigned long long int x) { return (Meter)x / 100; }
		Meter operator ""_mm(long double x) { return (Meter)x / 1000; }
		Meter operator ""_mm(unsigned long long int x) { return (Meter)x / 1000; }

		// Time
		Second operator ""_ms(long double x) { return (Second)x / 1000; }
		Second operator ""_ms(unsigned long long int x) { return (Second)x / 1000; }
		Second operator ""_s(long double x) { return (Second)x; }
		Second operator ""_s(unsigned long long int x) { return (Second)x; }
		Second operator ""_min(long double x) { return (Second)x * 60; }
		Second operator ""_min(unsigned long long int x) { return (Second)x * 60; }
		Second operator ""_hr(long double x) { return (Second)x * 3600; }
		Second operator ""_hr(unsigned long long int x) { return (Second)x * 3600; }
		Second operator ""_day(long double x) { return (Second)x * 3600 * 24; }
		Second operator ""_day(unsigned long long int x) { return (Second)x * 3600 * 24; }

		// Force
		Newton operator ""_N(long double x) { return (Newton)x; }
		Newton operator ""_N(unsigned long long int x) { return (Newton)x; }

		// Speed
		Speed operator ""_mPerS(long double x) { return (Speed)x; }
		Speed operator ""_mPerS(unsigned long long int x) { return (Speed)x; }
	}
}