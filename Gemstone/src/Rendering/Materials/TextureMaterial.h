#pragma once

#include "MaterialData.h"

#include "Rendering/OpenGL objects/Texture.h"
#include "Rendering/Shaders/ShaderLibrary.h"
#include "Rendering/Shaders/Uniforms/Uniform.h"

#include "Utility/Pointer.h"

namespace Gem {
	class TextureMaterial : public MaterialData {
	public:
		TextureMaterial(const Ptr<Texture>& texture)
			: MaterialData(ShaderLibrary::Get().imageShader), texture(texture) {

		}

		void use(const Matrix4f& model, const Matrix4f& view, const Matrix4f& projection) override {
			m_Program->use();
			m_Uniforms.upload();

			const Matrix4f modelViewProjection = model * view * projection;

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