#include "Input.h"

#include "Wavellite/Window.h"

#include "Wavellite/Input/Mouse.h"

namespace Emerald {
	void Input::Step(Esperite::Scene* scene) {
		Wavellite::Window::Get().pollEvents();
	}

	void Input::EndStep(Esperite::Scene* scene) {
		Wavellite::Mouse::Get().hasMoved = false;
	}
}