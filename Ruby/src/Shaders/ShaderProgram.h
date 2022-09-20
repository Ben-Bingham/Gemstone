#pragma once
#include <vector>

#include <GL/glew.h>

#include "VertexShader.h"
#include "FragmentShader.h"
#include "Vector.h"
#include "Matrix.h"
#include "Lights.h"

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

		// Basic uniforms
		void upload(const std::string& variableName, const int value) const {
			glUniform1i(glGetUniformLocation(m_Program, variableName.c_str()), value);
		}

		void upload(const std::string& variableName, const float value) const {
			glUniform1f(glGetUniformLocation(m_Program, variableName.c_str()), value);
		}

		void upload(const std::string& variableName, const Malachite::Matrix4f& matrix) const {
			glUniformMatrix4fv(glGetUniformLocation(m_Program, variableName.c_str()), 1, GL_FALSE, &matrix.row1.x);
		}

		void upload(const std::string& variableName, const Malachite::Vector3f& vector) const {
			glUniform3fv(glGetUniformLocation(m_Program, variableName.c_str()), 1, &vector.x);
		}

		void upload(const std::string& variableName, const Malachite::Vector4f& vector) const {
			glUniform4fv(glGetUniformLocation(m_Program, variableName.c_str()), 1, &vector.x);
		}

		// Advanced uniforms
		void upload(const std::string& variableName, const PointLight& pointLight) const {
			upload(variableName + ".position", pointLight.position);

			upload(variableName + ".ambient", pointLight.ambient);
			upload(variableName + ".diffuse", pointLight.diffuse);
			upload(variableName + ".specular", pointLight.specular);
		}

	private:
		unsigned int m_Program;
		std::vector<Attribute> m_Attributes;
	};
}