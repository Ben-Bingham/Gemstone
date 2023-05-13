#pragma once
#include "Window.h"
#include "Event System/EventSystem.h"
#include "Input/HumanInterfaceDeviceContext.h"
#include "Input/Keyboard.h"
#include "Input/Mouse.h"
#include "New Rendering/OpenGlContext.h"
#include "New Rendering/Renderer.h"
#include "New Rendering/User Interface/ImGuiContext.h"

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
		EventSystemManager eventManager{};
		HumanInterfaceDeviceContext humanInterfaceDeviceContext{};
		Window window{};
		OpenGlContext openGlContext{};
		ImGuiContext imGuiContext{};
		Renderer renderer{};
		// TODO add Logging as a subSystem

	private:
		Keyboard m_Keyboard{};
		Mouse m_Mouse{};

	} inline g_Engine;
}