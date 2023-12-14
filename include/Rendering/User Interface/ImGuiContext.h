#pragma once
#include "Core/SubSystem.h"
#include "Gem.h"

namespace Gem {
	class ImGuiContext : SubSystem {
	public:
		ImGuiContext() = default;
		ImGuiContext(const ImGuiContext& other) = default;
		ImGuiContext(ImGuiContext&& other) noexcept = default;
		ImGuiContext& operator=(const ImGuiContext& other) = default;
		ImGuiContext& operator=(ImGuiContext&& other) noexcept = default;
		~ImGuiContext() override = default;

		void StartUp() override;
		void ShutDown() override;

		void StartUiFrame();
		void RenderUi();

		bool imGuiIsActive{ false };
	};
}