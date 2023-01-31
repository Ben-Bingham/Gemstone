#include "MaterialManager.h"

#include "SolidMaterial.h"

namespace Ruby {
	MaterialManager& MaterialManager::Get() {
		static MaterialManager manager;

		return manager;
	}

	Celestite::Ptr<MaterialData> MaterialManager::CreateMaterial() { //TODO literal garbage
		if (m_Materials.empty()) {
			m_Materials.push_back(Celestite::CreatePtr<SolidMaterial>());
		}

		return m_Materials.back();
	}
}