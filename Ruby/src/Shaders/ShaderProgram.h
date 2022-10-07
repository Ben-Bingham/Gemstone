#pragma once
#include <vector>

#include <GL/glew.h>

#include "VertexShader.h"
#include "FragmentShader.h"
#include "GeometryShader.h"
#include "Vector.h"
#include "Matrix.h"
#include "Lights.h"
#include "OpenGl objects/Texture.h"
#include "OpenGL objects/Cubemap.h"
#include "Materials.h"

#include "OpenGL objects/VertexAttributeObject.h"

namespace Ruby {
	class ShaderProgram {
	public:
		ShaderProgram(const VertexShader& vertexShader, const FragmentShader& fragmentShader, const std::vector<Attribute>& attributes);
		ShaderProgram(const VertexShader& vertexShader, const GeometryShader& geometryShader, const FragmentShader& fragmentShader, const std::vector<Attribute>& attributes);
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

		void use() { 
			glUseProgram(m_Program); 
			activePorgram = this;
		}

		std::vector<Attribute> getAttributes() const {
			return m_Attributes;
		}

		// Basic uniforms Static Versions
		static void upload(const std::string& variableName, const int value) {
			glUniform1i(glGetUniformLocation(activePorgram->m_Program, variableName.c_str()), value);
		}

		static void upload(const std::string& variableName, const float value) {
			glUniform1f(glGetUniformLocation(activePorgram->m_Program, variableName.c_str()), value);
		}

		static void upload(const std::string& variableName, const Malachite::Matrix4f& matrix) {
			glUniformMatrix4fv(glGetUniformLocation(activePorgram->m_Program, variableName.c_str()), 1, GL_FALSE, &matrix.row1.x);
		}

		static void upload(const std::string& variableName, const Malachite::Vector3f& vector) {
			glUniform3fv(glGetUniformLocation(activePorgram->m_Program, variableName.c_str()), 1, &vector.x);
		}

		static void upload(const std::string& variableName, const Malachite::Vector4f& vector) {
			glUniform4fv(glGetUniformLocation(activePorgram->m_Program, variableName.c_str()), 1, &vector.x);
		}

		// Advanced uniforms
		static void upload(const std::string& variableName, const std::vector<PointLight*>& pointLights) {
			activePorgram->upload("numberOfPointLights", (int)pointLights.size());
			unsigned int i{ 0 };
			for (const PointLight* pointLight : pointLights) {
				activePorgram->upload(variableName + '[' + std::to_string(i) + ']', *pointLight);
				i++;
			}
		}

		static void upload(const std::string& variableName, unsigned int unit, const std::vector<DirectionalLight*>& directionalLights) {
			activePorgram->upload("numberOfdirectionalLights", (int)directionalLights.size());
			unsigned int i{ 0 };
			for (const DirectionalLight* directionalLight : directionalLights) {
				activePorgram->upload(variableName + '[' + std::to_string(i) + ']', unit + i, *directionalLight);
				i++;
			}
		}

		static void upload(const std::string& variableName, unsigned int unit, const Texture& texture) {
			texture.activateUnit(unit);
			texture.bind();
			activePorgram->upload(variableName, (int)unit);
		}

		static void upload(const std::string& variableName, unsigned int unit, const Cubemap& cubemap) {
			cubemap.activateUnit(unit);
			cubemap.bind();
			activePorgram->upload(variableName, (int)unit);
		}

		static void upload(const std::string& variableName, unsigned int startUnit, const PhongMaterial& material) {
			activePorgram->upload(variableName + ".diffuse", startUnit, *material.diffuse);
			activePorgram->upload(variableName + ".specular", startUnit + 1, *material.specular);
			activePorgram->upload(variableName + ".shininess", material.shininess);
		}

	private:
		static void upload(const std::string& variableName, const PointLight& pointLight) {
			activePorgram->upload(variableName + ".position", pointLight.position);

			activePorgram->upload(variableName + ".ambient", pointLight.ambient);
			activePorgram->upload(variableName + ".diffuse", pointLight.diffuse);
			activePorgram->upload(variableName + ".specular", pointLight.specular);

			activePorgram->upload(variableName + ".constant", pointLight.constant);
			activePorgram->upload(variableName + ".linear", pointLight.linear);
			activePorgram->upload(variableName + ".quadratic", pointLight.quadratic);
		}

		static void upload(const std::string& variableName, unsigned int unit, const DirectionalLight& directionalLight) {
			activePorgram->upload(variableName + ".direction", directionalLight.direction);

			activePorgram->upload(variableName + ".ambient", directionalLight.ambient);
			activePorgram->upload(variableName + ".diffuse", directionalLight.diffuse);
			activePorgram->upload(variableName + ".specular", directionalLight.specular);
			
			//activePorgram->upload(variableName + ".lightSpaceMatrix", directionalLight.spaceMatrix);
			//activePorgram->upload(variableName + ".shadowMap", unit, directionalLight.shadowMap);
		}

	private:
		unsigned int m_Program;
		std::vector<Attribute> m_Attributes;
		static ShaderProgram* activePorgram;
	};
}