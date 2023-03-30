#pragma once
#include "Scene.h"
#include "System.h"
#include "Utility/Pointer.h"

namespace Gem {
	class EntityComponentSystem {
	public:
		EntityComponentSystem() = default;

		void Load();
		void Step();
		void Unload();

		friend bool operator==(const EntityComponentSystem& lhs, const EntityComponentSystem& rhs);
		friend bool operator!=(const EntityComponentSystem& lhs, const EntityComponentSystem& rhs);

		Scene scene;
		std::vector<Ptr<System>> systems;
	};
}