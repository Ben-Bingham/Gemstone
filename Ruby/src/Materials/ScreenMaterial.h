#pragma once

#include "Material.h"

#include "Shaders/ShaderLibrary.h"
#include "Shaders/Uniforms/Uniform.h"
#include "Shaders/Uniforms/UniformSet.h"

namespace Ruby {
	class ScreenMaterial : public Material {
	public:
		ScreenMaterial(const Ptr<Texture>& texture)
			: Material(ShaderLibrary::get().screenQuadShader), texture(texture) {

		}

		void use(const Malachite::Matrix4f& model, const Malachite::Matrix4f& view, const Malachite::Matrix4f& projection) override {
			m_Program->use();
			m_Uniforms.upload();

			ShaderProgram::upload("model", model);
		}

		Ptr<Texture> texture;

	private:
		UniformSet<
			Texture
		> m_Uniforms{
			Uniform{ "image", *texture },
		};
	};
}