#pragma once

#include "Shaders/ShaderProgram.h"

namespace Ruby {
	class Material {
	public:
		explicit Material(ShaderProgram& program);

		virtual void use() = 0;

		[[nodiscard]] VertexShader::LayoutData getLayout() const;

	protected:
		ShaderProgram* m_Program;
	};
}