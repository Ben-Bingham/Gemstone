#pragma once
#include "Input/HumanInterfaceDeviceContext.h"
#include "Utility/Pointer.h"

namespace Gem {
	class Level;
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

		void ExecuteFrame(const Ptr<Level>& level) const;

		// Sub Systems
		HumanInterfaceDeviceContext humanInterfaceDeviceContext{};
	};
}