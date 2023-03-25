#include "MaterialManager.h"

namespace Ruby {
	using namespace Celestite;
	MaterialManager& MaterialManager::Get() {
		static MaterialManager manager;

		return manager;
	}
}