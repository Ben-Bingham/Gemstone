#pragma once
#include "Keys.h"

#include <GLFW/glfw3.h>

#include "Gem.h"

namespace Gem {
	void KeyCallback(GLFWwindow* window, int key, int scanCode, int action, int mods);

	class Keyboard final {
	public:
		Keyboard() = default;

		void StartUp();
		void ShutDown();

		bool GetKey(Key key);
	};
}