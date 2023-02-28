#pragma once

#include "Shaders/ShaderProgram.h"

namespace Ruby {
	class MaterialData { //TODO name could be better
	public:
		explicit MaterialData(ShaderProgram& program);
		virtual ~MaterialData() = default;

		virtual void staticUse() {}
		virtual void staticEnd() {}

		virtual void use(const Malachite::Matrix4f& model, const Malachite::Matrix4f& view, const Malachite::Matrix4f& projection) = 0;
		virtual void end();

		ShaderProgram& GetProgram() {
			return *m_Program;
		}

	protected:
		ShaderProgram* m_Program;
	};
}