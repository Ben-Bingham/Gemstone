#pragma once
#include "MaterialData.h"
#include "Utility/Pointer.h"

namespace Gem {
	class MaterialManager {
	public:
		MaterialManager(const MaterialManager& other) = delete;
		MaterialManager(MaterialManager&& other) noexcept = delete;
		MaterialManager& operator=(const MaterialManager& other) = delete;
		MaterialManager& operator=(MaterialManager&& other) noexcept = delete;
		~MaterialManager() = default;

		static MaterialManager& Get();

		template<typename T, typename ...Types>
		Ptr<MaterialData> CreateMaterial(Types&&... args) {
			for (Ptr<MaterialData>& material : m_Materials) {
				Ptr<T> phongMaterial = std::dynamic_pointer_cast<T>(material);
				if (phongMaterial != nullptr) {
					if (*phongMaterial == T(std::forward<Types>(args)...)) {
						return material;
					}
				}
			}

			m_Materials.push_back(CreatePtr<T>(std::forward<Types>(args)...));
			return m_Materials.back();
		}

	private:
		MaterialManager() = default;

		std::vector<Ptr<MaterialData>> m_Materials;
	};
}