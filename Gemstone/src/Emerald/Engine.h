#pragma once
#include "Celestite/Pointer.h"
#include "Esperite/Level.h"
#include "Wavellite/HumanInterfaceDeviceContext.h"

namespace Gem {
	/*
	Controls execution of Levels, when to render, when to start the next frame, ect.
	 */
	class Engine {
	public:
		Engine();
		Engine(const Engine& other) = default;
		Engine(Engine&& other) noexcept = default;
		Engine& operator=(const Engine& other) = default;
		Engine& operator=(Engine&& other) noexcept = default;
		~Engine();

		void ExecuteFrame(const Celestite::Ptr<Level>& level) const; //TODO rename to step

		// Sub Systems
		HumanInterfaceDeviceContext humanInterfaceDeviceContext{}; //TODO better name, glfw does not need to be included
	};
}