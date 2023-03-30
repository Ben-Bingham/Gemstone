#pragma once

#include "MaterialData.h"

#include "Shaders/ShaderLibrary.h"
#include "Shaders/Uniforms/Uniform.h"
#include "Shaders/Uniforms/UniformSet.h"

namespace Gem {
	class ScreenMaterial : public MaterialData {
	public:
		ScreenMaterial(const Ptr<Texture>& texture)
			: MaterialData(ShaderLibrary::Get().screenQuadShader), texture(texture) {

		}

		void use(const Matrix4f& model, const Matrix4f& view, const Matrix4f& projection) override {
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