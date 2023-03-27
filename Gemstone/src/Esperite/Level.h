#pragma once

#include "Emerald/EntityComponentSystem.h"

namespace Gem {
	class Level {
	public:
		Level() = default;
		Level(const Level& other) = default;
		Level(Level&& other) noexcept = default;
		Level& operator=(const Level& other) = default;
		Level& operator=(Level&& other) noexcept = default;
		virtual ~Level() = default;
		
		void Step();

		[[nodiscard]] bool IsRunning() const;
		void Stop();

	private:
		bool m_Running{ true };
		unsigned int m_FrameCount{ 0 };
		// Esperite::ECSScene m_Ecs{ };
		EntityComponentSystem m_ECS;
	};
}