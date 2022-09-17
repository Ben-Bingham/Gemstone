#pragma once
#include <vector>

#include <GL/glew.h>

#include "VertexShader.h"
#include "FragmentShader.h"
#include "Vector.h"
#include "Matrix.h"

#include "OpenGL objects/VertexAttributeObject.h"

namespace Ruby {
	class ShaderProgram {
	public:
		ShaderProgram(VertexShader& vertexShader, FragmentShader& fragmentShader, const std::vector<Attribute>& attributes);

		void use() const { glUseProgram(m_Program); }
		void dispose() { glDeleteProgram(m_Program); }

		std::vector<Attribute> getAttributes() const {
			return m_Attributes;
		}

		void setInt(const std::string& variableName, const int value) const {
			glUniform1i(glGetUniformLocation(m_Program, variableName.c_str()), value);
		}

		void setFloat(const std::string& variableName, const float value) const {
			glUniform1f(glGetUniformLocation(m_Program, variableName.c_str()), value);
		}

		void setMatrix4f(const std::string& variableName, const Malachite::Matrix4f& matrix) const {
			glUniformMatrix4fv(glGetUniformLocation(m_Program, variableName.c_str()), 1, GL_FALSE, &matrix.row1.x);
		}

		void setVector3f(const std::string& variableName, const Malachite::Vector3f& vector) const {
			glUniform3fv(glGetUniformLocation(m_Program, variableName.c_str()), 1, &vector.x);
		}

		void setVector4f(const std::string& variableName, const Malachite::Vector4f& vector) const {
			glUniform4fv(glGetUniformLocation(m_Program, variableName.c_str()), 1, &vector.x);
		}

	private:
		unsigned int m_Program;
		std::vector<Attribute> m_Attributes;
	};
}