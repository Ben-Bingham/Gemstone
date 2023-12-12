#pragma once
#include "Keys.h"

#include <GLFW/glfw3.h>

#include "Core/Window.h"
#include "Gem.h"

namespace Gem {
	void KeyCallback(GLFWwindow* window, int key, int scanCode, int action, int mods);

	class GEM_API Keyboard final : ISubSystem {
	public:
		Keyboard() = default;

		void StartUp() override;
		void ShutDown() override;

		bool GetKey(Key key);
	};
}