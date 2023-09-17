#pragma once
#include "Window.h"
#include "Event System/EventSystem.h"
#include "Input/HumanInterfaceDeviceContext.h"
#include "Input/Keyboard.h"
#include "Input/Mouse.h"
#include "Rendering/DebugRenderer.h"
#include "Rendering/OpenGlContext.h"
#include "Rendering/Renderer.h"
#include "Rendering/User Interface/ImGuiContext.h"

namespace Gem {
	class Engine {
	public:
		Engine();
		Engine(const Engine& other) = default;
		Engine(Engine&& other) noexcept = default;
		Engine& operator=(const Engine& other) = default;
		Engine& operator=(Engine&& other) noexcept = default;
		~Engine();

		// Sub Systems
		EventSystem& eventManager = EventSystem::Get();
		HumanInterfaceDeviceContext humanInterfaceDeviceContext{};
		Window window{};
		OpenGlContext openGlContext{};
		ImGuiContext imGuiContext{};
		Renderer renderer{};
		DebugRenderer debugRenderer{};

		Keyboard keyboard{};
		Mouse mouse{};

	};
	//inline g_Engine;
}