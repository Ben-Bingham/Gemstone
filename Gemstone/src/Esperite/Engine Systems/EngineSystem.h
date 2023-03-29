#pragma once

namespace Gem {
	class IEngineSystem {
	public:
		IEngineSystem() = default;
		virtual ~IEngineSystem() = default;

		virtual void StartUp() {}
		virtual void ShutDown() {}
	};
}