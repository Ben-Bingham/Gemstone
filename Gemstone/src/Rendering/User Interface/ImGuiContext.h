#pragma once
#include "Core/ISubSystem.h"

namespace Gem {
	class ImGuiContext : ISubSystem {
	public:
		ImGuiContext() = default;
		ImGuiContext(const ImGuiContext& other) = default;
		ImGuiContext(ImGuiContext&& other) noexcept = default;
		ImGuiContext& operator=(const ImGuiContext& other) = default;
		ImGuiContext& operator=(ImGuiContext&& other) noexcept = default;
		~ImGuiContext() override = default;

		void StartUp() override;
		void ShutDown() override;
	};
}