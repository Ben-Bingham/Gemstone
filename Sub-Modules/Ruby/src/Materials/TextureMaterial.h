#pragma once

#include "Material.h"

#include "Shaders/ShaderLibrary.h"
#include "Shaders/Uniforms/Uniform.h"
#include "Shaders/Uniforms/UniformSet.h"

namespace Ruby {
	class TextureMaterial : public Material {
	public:
		TextureMaterial(const Ptr<Texture>& texture)
			: Material(ShaderLibrary::get().imageShader), texture(texture) {

		}

		void use(const Malachite::Matrix4f& model, const Malachite::Matrix4f& view, const Malachite::Matrix4f& projection) override {
			m_Program->use();
			m_Uniforms.upload();

			const Malachite::Matrix4f modelViewProjection = model * view * projection;

			ShaderProgram::upload("modelViewProjection", modelViewProjection);
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