#pragma once
#include "Event System/EventSystem.h"

#include "Game Flow/Time.h"

#include "Input/GLFWContext.h"

namespace Gem {
	/*
	 * The Engine class represents the engine itself, it has the longest lifetime of any part of the application.
	 *
	 * The Engine class should manage the creation and deletion of all subsystems, but it should not control when they are run.
	 */
	class Engine_New {
	public:
		Engine_New();
		~Engine_New();

		Engine_New(const Engine_New& other) = default;
		Engine_New(Engine_New&& other) noexcept = default;
		Engine_New& operator=(const Engine_New& other) = default;
		Engine_New& operator=(Engine_New&& other) noexcept = default;

		EventSystem& eventSystem = EventSystem::Get();

		Time time{ };
		GLFWContext glfwContext{ };
		//Window window{};
		//OpenGlContext openGlContext{};
		//ImGuiContext imGuiContext{};
		//Renderer renderer{};
		//DebugRenderer debugRenderer{};

		//Keyboard keyboard{};
		//Mouse mouse{};
	};
}