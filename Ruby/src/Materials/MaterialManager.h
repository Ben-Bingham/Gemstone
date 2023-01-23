#pragma once
#include "MaterialData.h"
#include "Pointer.h"

namespace Ruby {
	class MaterialManager {
	public:
		MaterialManager(const MaterialManager& other) = delete;
		MaterialManager(MaterialManager&& other) noexcept = delete;
		MaterialManager& operator=(const MaterialManager& other) = delete;
		MaterialManager& operator=(MaterialManager&& other) noexcept = delete;
		~MaterialManager() = default;

		static MaterialManager& Get();

		Celestite::Ptr<MaterialData> NewMaterial(); // TODO this needs input

	private:
		MaterialManager() = default;

		std::vector<Celestite::Ptr<MaterialData>> m_Materials;
	};
}