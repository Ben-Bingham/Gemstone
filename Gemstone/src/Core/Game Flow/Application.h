#pragma once
#include "Core/Engine.h"
#include "Core/Window.h"
#include "Input/Keyboard.h"
#include "Input/Mouse.h"

namespace Gem {
	class Level;

	/*
	Controls overall flow of the game including, Order of levels, When to stop, ect
	 */
	class Application {
		Engine m_Engine{ Engine{} };
	public:
		Application() = default;

		void Load(const Ptr<Level>& level) const;

		Window window{ m_Engine.humanInterfaceDeviceContext };
		Keyboard keyboard{ window, m_Engine.humanInterfaceDeviceContext };
		Mouse mouse{ window, m_Engine.humanInterfaceDeviceContext };
		// Settings settings{}; //TODO needs to be dealt with
	};
}