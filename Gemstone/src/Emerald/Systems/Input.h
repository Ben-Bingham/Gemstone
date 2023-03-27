#pragma once
#include "Esperite/System.h"

namespace Emerald {
	class Input : public Esperite::System {
	public:
		Input() = default;
		~Input() override = default;

		void Step(Esperite::ECSScene* scene) override;
		void EndStep(Esperite::ECSScene* scene) override;
	};
}