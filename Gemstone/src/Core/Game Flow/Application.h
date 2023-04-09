#pragma once
#include "Level.h"
#include "Core/Engine.h"
#include "Core/Settings.h"

namespace Gem {
	class Application {
	public:
		Application() = default;

		// TODO needs to be redisigned to work with multiple levels
		void Load(const Ptr<Level>& level) const;

		void ExecuteFrame(const Ptr<Level>& level) const; // TODO maybe there should be a runtime class that handles this?

		Settings settings{}; //TODO needs to be dealt with
	};
}