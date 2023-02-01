#pragma once
#include "Material.h"
#include "MaterialData.h"
#include "Pointer.h"

namespace Ruby {
	using namespace Celestite;
	class MaterialManager {
	public:
		MaterialManager(const MaterialManager& other) = delete;
		MaterialManager(MaterialManager&& other) noexcept = delete;
		MaterialManager& operator=(const MaterialManager& other) = delete;
		MaterialManager& operator=(MaterialManager&& other) noexcept = delete;
		~MaterialManager() = default;

		static MaterialManager& Get();

		// Celestite::Ptr<MaterialData> CreateMaterial(); // TODO this needs input

		void RegisterMaterial(const Material& material);

	private:
		MaterialManager() = default;

		// std::vector<Celestite::Ptr<MaterialData>> m_Materials;
		std::vector<Material> m_Materials;
	};
}