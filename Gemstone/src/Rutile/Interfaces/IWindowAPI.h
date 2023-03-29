#pragma once
#include "Esperite/Engine Systems/EngineSystem.h"

#include "Ruby/WindowTarget.h"

namespace Rutile {
	class IWindowAPI : public Gem::IEngineSystem {
	public:
		IWindowAPI() = default;
		~IWindowAPI() override  = default;

		virtual Celestite::Ptr<Ruby::WindowTarget> CreateWindow(const std::string& title, const Malachite::Vector2ui& size, bool visible) = 0;
	};
}