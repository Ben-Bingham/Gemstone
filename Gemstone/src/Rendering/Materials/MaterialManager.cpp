#include "pch.h"
#include "MaterialManager.h"

namespace Gem {
	MaterialManager& MaterialManager::Get() {
		static MaterialManager manager;

		return manager;
	}
}