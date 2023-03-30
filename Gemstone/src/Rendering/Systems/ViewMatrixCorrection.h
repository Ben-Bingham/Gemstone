#pragma once
#include "Entity Component System/System.h"

namespace Gem {
	class ViewMatrixCorrection : public System {
	public:
		ViewMatrixCorrection() = default;
		~ViewMatrixCorrection() override = default;

		void Step(EntityComponentSystem& ecs) override;
	};
}