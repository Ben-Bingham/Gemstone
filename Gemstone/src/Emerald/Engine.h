#pragma once
#include "Wavellite/GLFWContext.h"

namespace Emerald {
	class Engine {
	public:
		Engine();
		Engine(const Engine& other) = default;
		Engine(Engine&& other) noexcept = default;
		Engine& operator=(const Engine& other) = default;
		Engine& operator=(Engine&& other) noexcept = default;
		~Engine();

	private:
		// Sub Systems
		Wavellite::GLFWContext m_GlfwContext{};
	};
}