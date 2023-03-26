#include "Time/Time.h"

#include <GLFW/glfw3.h>

namespace Gemstone {
	float Time::GetTime() {
		return (float)glfwGetTime();
	}
}