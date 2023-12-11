#pragma once
#include "Gem.h"

namespace Gem {
	class Engine_New;

	class GEM_API ISubSystem {
	public:
		ISubSystem() = default;
		ISubSystem(const ISubSystem& other) = default;
		ISubSystem(ISubSystem&& other) noexcept = default;
		ISubSystem& operator=(const ISubSystem& other) = default;
		ISubSystem& operator=(ISubSystem&& other) noexcept = default;
		virtual ~ISubSystem() = default;

		virtual void StartUp() = 0;
		virtual void ShutDown() = 0;
	};
}