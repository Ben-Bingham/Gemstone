#include "ShaderProgram.h"
#include "Log.h"

namespace Ruby {
	ShaderProgram::ShaderProgram(VertexShader& vertexShader, FragmentShader& fragmentShader) {
		int success;
		char infoLog[512];

		m_Program = glCreateProgram();

		glAttachShader(m_Program, vertexShader.getShader());
		glAttachShader(m_Program, fragmentShader.getShader());

		glLinkProgram(m_Program);

		glGetProgramiv(m_Program, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(m_Program, 512, NULL, infoLog);
			LOG("Shader program failed to link.\n" + std::string(infoLog), Lazuli::LogLevel::ERROR);
		}

		vertexShader.dispose();
		fragmentShader.dispose();
	}
}