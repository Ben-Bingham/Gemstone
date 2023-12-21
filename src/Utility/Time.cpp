#include "Utility/Time.h"
#include "Core/GLFWContext.h"

namespace Gem {
	float Time::GetTime() const {
		return (float)GLFWContext::Get().GetElapsedTime();
	}

	void Time::Wait(const float seconds) const {

		const float endPoint = GetTime() + seconds;

		while (GetTime() < endPoint) {}
	}
}