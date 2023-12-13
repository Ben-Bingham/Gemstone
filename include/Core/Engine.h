#pragma once
#include "Event System/EventSystem.h"
#include "Input/GLFWContext.h"
#include "Core/Window.h"

namespace Gem {
	/*
	 * The Engine class represents the engine itself, it has the longest lifetime of any part of the application.
	 *
	 * The Engine class should manage the creation and deletion of all subsystems, but it should not control when they are run.
	 */
	class Engine {
	public:
		Engine();
		~Engine();

		Engine(const Engine& other) = default;
		Engine(Engine&& other) noexcept = default;
		Engine& operator=(const Engine& other) = default;
		Engine& operator=(Engine&& other) noexcept = default;

		EventSystem eventSystem{ };
		GLFWContext glfwContext{ };
		Window window{ };
		//OpenGlContext openGlContext{};
		//ImGuiContext imGuiContext{};
		//Renderer renderer{};
		//DebugRenderer debugRenderer{};

		//Keyboard keyboard{};
		//Mouse mouse{};
	};
}