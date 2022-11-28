#include "ShaderLibrary.h"

namespace Ruby {
	ShaderLibrary& ShaderLibrary::get() {
		static ShaderLibrary instance;

		return instance;
	}

	void ShaderLibrary::upload(const std::string& variableName, const Malachite::Matrix4f& value) const {
		for (ShaderProgram* program : m_Programs) {
			program->use();
			ShaderProgram::upload(variableName, value);
		}
	}

}