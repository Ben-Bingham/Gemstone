#pragma once

#include "OpenGLContext.h"

#include "Shaders/ShaderProgram.h"

namespace Ruby {
	class Material {
	public:
		explicit Material(ShaderProgram& program);

		virtual OpenGlContext use(const Malachite::Matrix4f& model, const Malachite::Matrix4f& view, const Malachite::Matrix4f& projection) = 0;

		[[nodiscard]] VertexShader::LayoutData getLayout() const;

	protected:
		ShaderProgram* m_Program;
	};
}