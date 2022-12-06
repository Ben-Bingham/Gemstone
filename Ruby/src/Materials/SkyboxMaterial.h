#pragma once
#include "Material.h"
#include "OpenGLState.h"

#include "OpenGL objects/Cubemap.h"

#include "Shaders/ShaderLibrary.h"
#include "Shaders/Uniforms/UniformSet.h"
#include "Shaders/Uniforms/Uniform.h"

namespace Ruby {
	class SkyBoxMaterial : public Material {
	public:
		SkyBoxMaterial(const std::initializer_list<Ptr<Image>>& faces)
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

			std::get<0>(m_SavedOpenGlState) = OpenGlState::get().getDepthFunction();
			std::get<1>(m_SavedOpenGlState) = OpenGlState::get().getFaceToCull();
			std::get<2>(m_SavedOpenGlState) = OpenGlState::get().getDepthBufferWriting();

			OpenGlState::get().setDepthFunction(OpenGlState::Comparison::LESS_THAN_OR_EQUAL);
			OpenGlState::get().setFaceToCull(OpenGlState::Face::FRONT);
			OpenGlState::get().setDepthBufferWriting(false);
		}

		void end() override {
			OpenGlState::get().setDepthFunction(get<0>(m_SavedOpenGlState));
			OpenGlState::get().setFaceToCull(get<1>(m_SavedOpenGlState));
			OpenGlState::get().setDepthBufferWriting(get<2>(m_SavedOpenGlState));
		}

		Cubemap cubeMap;

	private:
		UniformSet<
			Cubemap
		> m_Uniforms{
			Uniform{"cubeMap", cubeMap}
		};

		std::tuple< OpenGlState::Comparison, OpenGlState::Face, bool> m_SavedOpenGlState;
	};
}