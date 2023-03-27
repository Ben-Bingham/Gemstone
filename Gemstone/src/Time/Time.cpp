#include "pch.h"
#include "Time/Time.h"

#include <GLFW/glfw3.h>

namespace Gem {
	float Time::GetTime() {
		return (float)glfwGetTime();
	}
}