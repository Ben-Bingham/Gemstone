#pragma once
#include "Wavellite/Window.h"

namespace Apatite {
	class Application {
	public:
		Application() = default;

		void Start() const;
		void Interrupt() const;

		Wavellite::Window window{ };
		// Emerald::ECSManager engine{ }; // TODO if engine is going to be used in this context than its name should be changed, maybe change to ECS
	};
}