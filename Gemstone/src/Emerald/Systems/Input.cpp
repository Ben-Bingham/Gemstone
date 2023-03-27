#include "pch.h"
#include "Input.h"

#include "Wavellite/Window.h"

#include "Wavellite/Input/Mouse.h"

namespace Emerald {
	void Input::Step(Esperite::ECSScene* scene) {
		Wavellite::Window::Get().pollEvents();
	}

	void Input::EndStep(Esperite::ECSScene* scene) {
		Wavellite::Mouse::Get().hasMoved = false;
	}
}