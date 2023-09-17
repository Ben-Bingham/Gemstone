#pragma once
#include "Core/ISubSystem.h"

namespace Gem {
	class Time : ISubSystem {
	public:
		Time() = default;

		void StartUp() override;
		void ShutDown() override;

		[[nodiscard]] std::chrono::microseconds GetElapsedTime() const;
		void Wait(std::chrono::seconds seconds) const;
		void Wait(std::chrono::milliseconds milliseconds) const;
		void Wait(std::chrono::microseconds microseconds) const;

	private:
		std::chrono::time_point<std::chrono::steady_clock> m_StartTime;
	};
}