#include "Input.h"

#include "Window.h"

#include "Input/Mouse.h"

namespace Emerald {
	void Input::Step(Esperite::Scene* scene) {
		Wavellite::Window::Get().pollEvents();
	}

	void Input::EndStep(Esperite::Scene* scene) {
		Wavellite::Mouse::Get().hasMoved = false;
	}
}