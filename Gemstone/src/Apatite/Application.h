#pragma once
#include "Settings.h"

#include "Celestite/Pointer.h"
#include "Emerald/Engine.h"
#include "Esperite/Level.h"
#include "Wavellite/Window.h"
#include "Wavellite/Input/Keyboard.h"
#include "Wavellite/Input/Mouse.h"

namespace Gem {
	/*
	Controls overall flow of the game including, Order of levels, When to stop, ect
	 */
	class Application {
		Engine m_Engine{ Engine{} };
	public:
		Application() = default;

		void Load(const Celestite::Ptr<Level>& level) const;

		Window window{ m_Engine.humanInterfaceDeviceContext };
		Keyboard keyboard{ window, m_Engine.humanInterfaceDeviceContext };
		Mouse mouse{ window, m_Engine.humanInterfaceDeviceContext };
		// Settings settings{}; //TODO needs to be dealt with
	};
}