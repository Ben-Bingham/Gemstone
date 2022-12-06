#pragma once

#include "Shaders/ShaderProgram.h"

namespace Ruby {
	class Material {
	public:
		explicit Material(ShaderProgram& program);

		virtual void use(const Malachite::Matrix4f& model, const Malachite::Matrix4f& view, const Malachite::Matrix4f& projection) = 0;
		virtual void end();

	protected:
		ShaderProgram* m_Program;
	};
}