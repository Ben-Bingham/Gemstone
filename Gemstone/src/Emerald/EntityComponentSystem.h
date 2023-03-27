#pragma once
#include "Celestite/Pointer.h"

#include "Esperite/ECSScene.h"
#include "Esperite/System.h"

namespace Gem {
	class EntityComponentSystem {
	public:
		EntityComponentSystem() = default;

		void Load();
		void Step();
		void Unload();

	private:
		Esperite::ECSScene m_Scene;
		std::vector<Celestite::Ptr<Esperite::System>> m_Systems;
	};
}