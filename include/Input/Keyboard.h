#pragma once
#include "Keys.h"

#include <GLFW/glfw3.h>

#include "Gem.h"
#include "Core/SubSystem.h"

namespace Gem {
	void KeyCallback(GLFWwindow* window, int key, int scanCode, int action, int mods);

	class Keyboard final : SubSystem {
	public:
		Keyboard() = default;

		void StartUp() override;
		void ShutDown() override;

		bool GetKey(Key key);
	};
}