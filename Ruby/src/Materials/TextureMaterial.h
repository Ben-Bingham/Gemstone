#pragma once

#include "MaterialData.h"

#include "Shaders/ShaderLibrary.h"
#include "Shaders/Uniforms/Uniform.h"
#include "Shaders/Uniforms/UniformSet.h"

namespace Ruby {
	class TextureMaterial : public MaterialData {
	public:
		TextureMaterial(const Celestite::Ptr<Texture>& texture)
			: MaterialData(ShaderLibrary::get().imageShader), texture(texture) {

		}

		void use(const Malachite::Matrix4f& model, const Malachite::Matrix4f& view, const Malachite::Matrix4f& projection) override {
			m_Program->use();
			m_Uniforms.upload();

			const Malachite::Matrix4f modelViewProjection = model * view * projection;

			ShaderProgram::upload("modelViewProjection", modelViewProjection);
		}

		Celestite::Ptr<Texture> texture;

	private:
		UniformSet<
			Texture
		> m_Uniforms{
			Uniform{ "image", *texture },
		};
	};
}