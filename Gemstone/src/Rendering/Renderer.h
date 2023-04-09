#pragma once
#include "Core/ISubSystem.h"

namespace Gem {
	class Renderer : ISubSystem{
	public:
		Renderer() = default;

		void StartUp() override;
		void ShutDown() override;

		void StartUiFrame();

		void Render();

	private:
		void RenderSetup();
		void RenderCleanup();

		void RenderUI();
	};
}