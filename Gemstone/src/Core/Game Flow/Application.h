#pragma once
#include "Level.h"
#include "Core/Engine.h"
#include "Core/Settings.h"

namespace Gem {
	class Application {
		struct DebugTimings {
			float frameTime;
			float frameStart;
			float frameEnd;

			float uiPrepTime;
			float uiPrepStart;
			float uiPrepEnd;

			float eventPollingTime;
			float eventPollStart;
			float eventPollEnd;

			float eventDistributionTime;
			float eventDistributionStart;
			float eventDistributionEnd;

			float ecsTime;
			float ecsStart;
			float ecsEnd;

			float renderSetupTime;
			float renderSetupStart;
			float renderSetupEnd;

			float renderTime;
			float renderStart;
			float renderEnd;

			float uiTime;
			float uiStart;
			float uiEnd;

			float renderCleanupTime;
			float renderCleanupStart;
			float renderCleanupEnd;

			float totalGpuTime;
			float totalGpuStart;
			float totalGpuEnd;

			float totalCpuTime;
			float totalCpuStart;
			float totalCpuEnd;
		};

	public:
		Application() = default;

		// TODO needs to be redisigned to work with multiple levels
		void Load(const Ptr<Level>& level) const;

		void ExecuteFrame(const Ptr<Level>& level) const; // TODO maybe there should be a runtime class that handles this?

		Settings settings{}; //TODO needs to be dealt with

	private:
		void DrawDebugWindow(const DebugTimings& timings) const;

		mutable float m_LastEndTime{ 0.0f };

		bool m_DebugWindow{ true };
	};
}