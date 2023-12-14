#include "Utility/Time.h"

namespace Gem {
	Time::Time(GLFWContext& context)
		: m_Context(context) { }

	float Time::GetTime() const {
		return (float)m_Context.GetElapsedTime();
	}

	void Time::Wait(const float seconds) const {

		const float endPoint = GetTime() + seconds;

		while (GetTime() < endPoint) {}
	}
}