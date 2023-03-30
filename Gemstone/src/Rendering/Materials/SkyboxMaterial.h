#pragma once
#include "MaterialData.h"

#include "Rendering/OpenGLState.h"
#include "Rendering/OpenGL objects/Cubemap.h"
#include "Rendering/Resources/Image.h"
#include "Rendering/Shaders/ShaderLibrary.h"
#include "Rendering/Shaders/Uniforms/Uniform.h"

#include "Utility/Pointer.h"

namespace Gem {
	class SkyBoxMaterial : public MaterialData {
	public:
		SkyBoxMaterial(const std::initializer_list<Ptr<Image>>& faces)
			: MaterialData(ShaderLibrary::Get().skyBoxShader), cubeMap(faces) {
			
		}

		void use(const Matrix4f& model, const Matrix4f& view, const Matrix4f& projection) override {
			m_Program->use();
			m_Uniforms.upload();

			Matrix4f viewMat = Matrix4f{
				Vector4f{view.row1.x, view.row1.y, view.row1.z, 0.0f},
				Vector4f{view.row2.x, view.row2.y, view.row2.z, 0.0f},
				Vector4f{view.row3.x, view.row3.y, view.row3.z, 0.0f},
				Vector4f{0.0f, 0.0f, 0.0f, 1.0f}
			};

			Matrix4f viewProjection = viewMat * projection;
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