#pragma once
#include "ECSScene.h"

namespace Esperite {
	class System {
	public:
		System();

		virtual ~System() = default;

		virtual void StartUp(ECSScene* scene); //TODO should be able to get iterators for spedcific type of InternalGameObject as opposd to the whole scene.
		virtual void PreStep(ECSScene* scene);
		virtual void Step(ECSScene* scene);
		virtual void EndStep(ECSScene* scene);
		virtual void ShutDown(ECSScene* scene);

		static inline ECSScene* activeScene{ nullptr };

	private:
		ECSScene* m_Owner{activeScene};
	};
}