#pragma once
#include "Core/ISubSystem.h"

#include "Utility/Colour.h"

#define DEBUG_RENDERER_ON_RELEASE

#if defined GEMSTONE_DEBUG || defined DEBUG_RENDERER_ON_RELEASE
#define DEBUG_RENDERER
#endif

namespace Gem {
	class DebugRenderer : ISubSystem {
	public:
		DebugRenderer() = default;
		DebugRenderer(const DebugRenderer& other) = default;
		DebugRenderer(DebugRenderer&& other) noexcept = default;
		DebugRenderer& operator=(const DebugRenderer& other) = default;
		DebugRenderer& operator=(DebugRenderer&& other) noexcept = default;
		~DebugRenderer() override = default;

		void StartUp() override;
		void ShutDown() override;

		void DrawLine(const Vector3f& start, const Vector3f& end, const Colour& colour);

		void Render();
	};
}