#pragma once

#include "Rendering/Shaders/ShaderProgram.h"

namespace Gem {
	class MaterialData { //TODO name could be better
	public:
		explicit MaterialData(ShaderProgram& program);
		virtual ~MaterialData() = default;

		virtual void staticUse() {}
		virtual void staticEnd() {}

		virtual void use(const Matrix4f& model, const Matrix4f& view, const Matrix4f& projection) = 0;
		virtual void end();

		ShaderProgram& GetProgram() {
			return *m_Program;
		}

	protected:
		ShaderProgram* m_Program;
	};
}