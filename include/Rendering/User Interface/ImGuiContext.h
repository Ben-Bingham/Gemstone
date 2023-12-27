#pragma once
//#include "Core/SubSystem.h"
#include "Gem.h"

namespace Gem {
	class ImGuiContext {
	public:
		ImGuiContext() = default;
		ImGuiContext(const ImGuiContext& other) = default;
		ImGuiContext(ImGuiContext&& other) noexcept = default;
		ImGuiContext& operator=(const ImGuiContext& other) = default;
		ImGuiContext& operator=(ImGuiContext&& other) noexcept = default;
		~ImGuiContext() = default;

		void StartUp() ;
		void ShutDown() ;

		void StartUiFrame();
		void RenderUi();

		bool imGuiIsActive{ false };
	};
}