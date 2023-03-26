#include "Application.h"

#include <GLFW/glfw3.h>

#include "Time/Time.h"

#include "Lazuli/Log.h"

namespace Apatite {
	void Application::Start() const {
		while(window.IsOpen()) {
			glfwPollEvents();

			LOG(std::to_string(Gemstone::Time::GetTime()));
		}
	}

	void Application::Interrupt() const {
		window.Close();
	}
}