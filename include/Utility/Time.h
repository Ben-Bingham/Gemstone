#pragma once

namespace Gem {
	class Time {
	public:
		Time() = default;

		[[nodiscard]] float GetTime() const;

		void Wait(float seconds) const;
	};
}