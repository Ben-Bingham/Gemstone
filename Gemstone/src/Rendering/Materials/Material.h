#pragma once
#include "ColourInput.h"
#include "MaterialData.h"

namespace Gem {
	class Material {
	public:
		Material() = default;

		Ptr<MaterialData> material;

	// 	void Initialize();
	// 	void Use() const;
	//
	// 	Ptr<ColourInput> diffuse;
	// 	Ptr<ColourInput> specular;
	// 	Ptr<ColourInput> shininess;
	//
	// private:
	// 	Ptr<ShaderProgram> m_Shader;
	// 	bool m_Initialized{ false };
	};
}