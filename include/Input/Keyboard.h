#pragma once
#include <GLFW/glfw3.h>
#include "Keys.h"

namespace Gem {
	void KeyCallback(GLFWwindow* window, int key, int scanCode, int action, int mods);

	class Keyboard {
		friend class Engine;

		static void StartUp();
		static void ShutDown();

		Keyboard() = default;
		~Keyboard() = default;

		static inline bool m_Started{ false };

	public:
		static Keyboard& Get();

		Keyboard(const Keyboard& other) = delete;
		Keyboard(Keyboard&& other) noexcept = default;
		Keyboard& operator=(const Keyboard& other) = delete;
		Keyboard& operator=(Keyboard&& other) noexcept = default;

		bool GetKey(Key key);
	};
}