#pragma once
#include "System.h"

namespace Ruby {
	class ViewMatrixCorrection : public Esperite::System {
	public:
		ViewMatrixCorrection() = default;
		~ViewMatrixCorrection() override = default;

		void Step(Esperite::Scene* scene) override;
	};
}