#pragma once
#include "Gem.h"

namespace Gem {
	class IEventTypeManager {
	public:
		IEventTypeManager() = default;
		IEventTypeManager(const IEventTypeManager& other) = default;
		IEventTypeManager(IEventTypeManager&& other) noexcept = default;
		IEventTypeManager& operator=(const IEventTypeManager& other) = default;
		IEventTypeManager& operator=(IEventTypeManager&& other) noexcept = default;
		virtual ~IEventTypeManager() = default;

		virtual void Distribute() = 0;
	};

}