#pragma once

#include "OpenGLContext.h"

#include "Shaders/ShaderProgram.h"

namespace Ruby {
	class Material {
	public:
		explicit Material(ShaderProgram& program);

		virtual void use(const Malachite::Matrix4f& model, const Malachite::Matrix4f& view, const Malachite::Matrix4f& projection) = 0;
		virtual void end();

		[[nodiscard]] VertexShader::LayoutData getLayout() const;

	protected:
		ShaderProgram* m_Program;
	};
}