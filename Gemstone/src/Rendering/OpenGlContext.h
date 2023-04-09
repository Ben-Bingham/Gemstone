#pragma once
#include "Core/ISubSystem.h"

namespace Gem {
	class OpenGlContext : ISubSystem {
	public:
		OpenGlContext() = default;
		OpenGlContext(const OpenGlContext& other) = default;
		OpenGlContext(OpenGlContext&& other) noexcept = default;
		OpenGlContext& operator=(const OpenGlContext& other) = default;
		OpenGlContext& operator=(OpenGlContext&& other) noexcept = default;
		~OpenGlContext() override = default;

		void StartUp() override;
		void ShutDown() override;
	};
}