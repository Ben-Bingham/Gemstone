#include "pch.h"
#include "Input.h"

#include "Wavellite/Window.h"

#include "Wavellite/Input/Mouse.h"

namespace Emerald {
	void Input::Step(Gem::EntityComponentSystem& ecs) {
		// Gem::Window::Get().pollEvents();
	}

	void Input::EndStep(Gem::EntityComponentSystem& ecs) {
		// Gem::Mouse::Get().hasMoved = false;
	}
}