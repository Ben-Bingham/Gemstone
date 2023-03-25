#pragma once
#include "Scene.h"

namespace Esperite {
	class System {
	public:
		System() = default;

		virtual ~System() = default;

		virtual void StartUp(Scene* scene); //TODO should be able to get iterators for spedcific type of GameObject as opposd to the whole scene.
		virtual void PreStep(Scene* scene);
		virtual void Step(Scene* scene);
		virtual void EndStep(Scene* scene);
		virtual void ShutDown(Scene* scene);

	};
}