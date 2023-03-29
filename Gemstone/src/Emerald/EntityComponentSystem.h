#pragma once
#include "Celestite/Pointer.h"
#include "Esperite/Scene.h"
#include "Esperite/System.h"

namespace Gem {
	class EntityComponentSystem {
	public:
		EntityComponentSystem() = default;

		void Load();
		void Step();
		void Unload();

		friend bool operator==(const EntityComponentSystem& lhs, const EntityComponentSystem& rhs) {
			return lhs.scene == rhs.scene
				&& lhs.systems == rhs.systems;
		}

		friend bool operator!=(const EntityComponentSystem& lhs, const EntityComponentSystem& rhs) { return !(lhs == rhs); }

		Scene scene;
		std::vector<Celestite::Ptr<System>> systems;
	};
}