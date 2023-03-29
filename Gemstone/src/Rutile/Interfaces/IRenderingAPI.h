#pragma once
#include "Esperite/Engine Systems/EngineSystem.h"

namespace Rutile {
	class IRenderingAPI : public Gem::IEngineSystem {
	public:
		IRenderingAPI() = default;
		~IRenderingAPI() override = default;

		virtual void CreateContext() {}
		virtual void ClearColour(const Ruby::Colour& colour) {}
		virtual void ClearColorBit() {}
		virtual void ClearDepthBit() {}
		virtual void DrawMesh() {}
	};
}