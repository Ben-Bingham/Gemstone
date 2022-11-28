#pragma once
#include "Material.h"
#include "OpenGL objects/Cubemap.h"

#include "Shaders/ShaderLibrary.h"
#include "Shaders/Uniforms/UniformSet.h"
#include "Shaders/Uniforms/Uniform.h"

namespace Ruby {
	class SkyBoxMaterial : public Material {
	public:
		SkyBoxMaterial(const std::initializer_list<Image>& faces)
			: Material(ShaderLibrary::get().skyBoxShader), cubeMap(faces) {
			
		}

		void use() override {
			m_Program->use();
			m_Uniforms.upload();
		}

		Cubemap cubeMap;

	private:
		UniformSet<
			Cubemap
		> m_Uniforms{
			Uniform{"cubeMap", cubeMap}
		};
	};
}