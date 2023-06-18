#pragma once
#include "Core/Event System/EventHandler.h"
#include "Entity Component System/System.h"
#include "Core/WindowEvents.h"

namespace Gem {
	class RenderingSystem final : public System, EventHandler<WindowEvents::Resize> {
	public:
		RenderingSystem() = default;

		void Step(EntityManager& entityManager, float dt) override;

		void HandleEvent(const WindowEvents::Resize& event) override;
	};
}