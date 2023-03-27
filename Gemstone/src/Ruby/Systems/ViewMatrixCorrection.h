#pragma once
#include "Esperite/System.h"

namespace Ruby {
	class ViewMatrixCorrection : public Esperite::System {
	public:
		ViewMatrixCorrection() = default;
		~ViewMatrixCorrection() override = default;

		void Step(Esperite::ECSScene* scene) override;
	};
}