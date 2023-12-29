#pragma once

namespace Gem {
	class Time {
	public:
		Time() = default;

		[[nodiscard]] float GetTime() const;

		void Wait(float seconds) const;

		inline static float deltaTime{ 1.0f / 60.0f };
	};
}