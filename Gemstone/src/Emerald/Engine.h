#pragma once
#include "Celestite/Pointer.h"

#include "Esperite/Level.h"

#include "Wavellite/GLFWContext.h"

namespace Gem {
	class Engine {
	public:
		Engine();
		Engine(const Engine& other) = default;
		Engine(Engine&& other) noexcept = default;
		Engine& operator=(const Engine& other) = default;
		Engine& operator=(Engine&& other) noexcept = default;
		~Engine();

		void ExecuteFrame(const Celestite::Ptr<Level>& scene) const; //TODO rename to step

		// Sub Systems
		GLFWContext glfwContext{}; //TODO better name, glfw does not need to be included
	};
}