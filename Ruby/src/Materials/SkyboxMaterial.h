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

		void use(const Malachite::Matrix4f& model, const Malachite::Matrix4f& view, const Malachite::Matrix4f& projection) override {
			m_Program->use();
			m_Uniforms.upload();

			Malachite::Matrix4f viewMat = Malachite::Matrix4f{
				Malachite::Vector4f{view.row1.x, view.row1.y, view.row1.z, 0.0f},
				Malachite::Vector4f{view.row2.x, view.row2.y, view.row2.z, 0.0f},
				Malachite::Vector4f{view.row3.x, view.row3.y, view.row3.z, 0.0f},
				Malachite::Vector4f{0.0f, 0.0f, 0.0f, 1.0f}
			};

			Malachite::Matrix4f viewProjection = viewMat * projection;
			ShaderProgram::upload("viewProjection", viewProjection);
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