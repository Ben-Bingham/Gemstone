#pragma once
#include "Entity Component System/System.h"

namespace Gem {
	class RenderingSystem final : public System {
	public:
		RenderingSystem() = default;

		void Step(EntityManager& entityManager, float dt) override;
	};
}