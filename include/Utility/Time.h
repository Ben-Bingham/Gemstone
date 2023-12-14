#pragma once
#include "Core/GLFWContext.h"

namespace Gem {
	class Time {
	public:
		Time(GLFWContext& context);
		[[nodiscard]] float GetTime() const;

		void Wait(float seconds) const;

	private:
		GLFWContext& m_Context;
	};
}