#pragma once
#include "System.h"

namespace Emerald {
	class Input : public Esperite::System {
	public:
		Input() = default;
		~Input() override = default;

		void Step(Esperite::Scene* scene) override;
		void EndStep(Esperite::Scene* scene) override;
	};
}