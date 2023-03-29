#pragma once
#include "Esperite/System.h"

namespace Ruby {
	class ViewMatrixCorrection : public Gem::System {
	public:
		ViewMatrixCorrection() = default;
		~ViewMatrixCorrection() override = default;

		void Step(Gem::EntityComponentSystem& ecs) override;
	};
}