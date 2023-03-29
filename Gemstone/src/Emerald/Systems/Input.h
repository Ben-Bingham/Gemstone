#pragma once
#include "Esperite/System.h"

namespace Emerald {
	class Input : public Gem::System {
	public:
		Input() = default;
		~Input() override = default;

		void Step(Gem::EntityComponentSystem& ecs) override;
		void EndStep(Gem::EntityComponentSystem& ecs) override;
	};
}