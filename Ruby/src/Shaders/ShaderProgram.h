#pragma once
#include <vector>

#include <GL/glew.h>

#include "VertexShader.h"
#include "FragmentShader.h"
#include "Vector.h"
#include "Matrix.h"
#include "Lights.h"
#include "Texture.h"
#include "Materials.h"

#include "OpenGL objects/VertexAttributeObject.h"

namespace Ruby {
	class ShaderProgram {
	public:
		ShaderProgram(const VertexShader& vertexShader, const FragmentShader& fragmentShader, const std::vector<Attribute>& attributes);
		~ShaderProgram() { glDeleteProgram(m_Program); }
		ShaderProgram(ShaderProgram&) = delete;
		ShaderProgram& operator=(ShaderProgram&) = delete;
		ShaderProgram(ShaderProgram&& other) noexcept 
			: m_Program(std::move(other.m_Program)),
			  m_Attributes(std::move(other.m_Attributes)) {
			other.m_Program = 0;
		}

		ShaderProgram& operator=(ShaderProgram&& other) noexcept {
			m_Program = std::move(other.m_Program);
			other.m_Program = 0;

			m_Attributes = std::move(other.m_Attributes);
		}

		void use() const { glUseProgram(m_Program); }

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

		void upload(const std::string& variableName, unsigned int unit, const Texture& texture) const {
			texture.activateUnit(unit);
			texture.bind();
			upload("variableName", (int)unit);
		}

		void upload(const std::string& variableName, unsigned int startUnit, const Material& material) const {
			upload(variableName + ".diffuse", startUnit, *material.diffuse);
			upload(variableName + ".specular", startUnit + 1, *material.specular);
			upload(variableName + ".shininess", material.shininess);
		}

	private:
		unsigned int m_Program;
		std::vector<Attribute> m_Attributes;
	};
}