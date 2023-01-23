#pragma once
#include <vector>

#include "GameObject.h"
#include "Scene.h"

namespace Esperite {
	class System {
	public:
		System() = default;

		virtual ~System() = default;

		virtual void Process(Scene* scene) = 0;
	};
}