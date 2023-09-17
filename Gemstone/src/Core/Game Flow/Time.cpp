#include "pch.h"
#include "Time.h"

namespace Gem {
	void Time::StartUp() {
		m_StartTime = std::chrono::high_resolution_clock::now();
	}

	void Time::ShutDown() { }

	std::chrono::microseconds Time::GetElapsedTime() const {
		return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - m_StartTime);
	}

	void Time::Wait(const std::chrono::seconds seconds) const {
		Wait(std::chrono::duration_cast<std::chrono::microseconds>(seconds));
	}

	void Time::Wait(const std::chrono::milliseconds milliseconds) const {
		Wait(std::chrono::duration_cast<std::chrono::microseconds>(milliseconds));
	}

	void Time::Wait(const std::chrono::microseconds microseconds) const {
		const std::chrono::time_point<std::chrono::steady_clock> endPoint = std::chrono::high_resolution_clock::now() + microseconds;

		while (std::chrono::high_resolution_clock::now() < endPoint) { }
	}
}