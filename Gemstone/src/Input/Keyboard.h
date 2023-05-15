#pragma once
#include "Keys.h"

#include <GLFW/glfw3.h>

#include "Core/Window.h"

namespace Gem {
	void KeyCallback(GLFWwindow* window, int key, int scanCode, int action, int mods);

	class Keyboard final : ISubSystem {
	public:
		Keyboard() = default;

		void StartUp() override;
		void ShutDown() override;

		bool GetKey(Key key);
	};
}