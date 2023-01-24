#include "Input.h"

#include "Window.h"

namespace Emerald {
	void Input::Step(Esperite::Scene* scene) {
		Wavellite::Window::Get().pollEvents();
	}
}