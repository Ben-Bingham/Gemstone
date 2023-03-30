#include "pch.h"
#include "ShaderProgram.h"
#include "ShaderLibrary.h"


namespace Gem {
	ShaderProgram::ShaderProgram(const VertexShader& vertexShader, const FragmentShader& fragmentShader) {
		int success;

		m_Program = glCreateProgram();

		glAttachShader(m_Program, vertexShader.getShader());
		glAttachShader(m_Program, fragmentShader.getShader());

		glLinkProgram(m_Program);

		glGetProgramiv(m_Program, GL_LINK_STATUS, &success);
		if (!success) {
			char infoLog[512];
			glGetProgramInfoLog(m_Program, 512, NULL, infoLog);
			LOG("Shader program failed to link.\n" + std::string(infoLog), LogLevel::ERROR);
		}

		m_PathHash = std::hash<std::string>{}(vertexShader.getShaderSourceFile().getPath() + fragmentShader.getShaderSourceFile().getPath());
	}

	ShaderProgram::ShaderProgram(const VertexShader& vertexShader, const GeometryShader& geometryShader, const FragmentShader& fragmentShader) {
		int success;

		m_Program = glCreateProgram();

		glAttachShader(m_Program, vertexShader.getShader());
		glAttachShader(m_Program, geometryShader.getShader());
		glAttachShader(m_Program, fragmentShader.getShader());

		glLinkProgram(m_Program);

		glGetProgramiv(m_Program, GL_LINK_STATUS, &success);
		if (!success) {
			char infoLog[512];
			glGetProgramInfoLog(m_Program, 512, NULL, infoLog);
			LOG("Shader program failed to link.\n" + std::string(infoLog), LogLevel::ERROR);
		}

		m_PathHash = std::hash<std::string>{}(vertexShader.getShaderSourceFile().getPath() + geometryShader.getShaderSourceFile().getPath() + fragmentShader.getShaderSourceFile().getPath());
	}

	ShaderProgram::ShaderProgram(ShaderProgram&& other) noexcept
		: m_Program(std::move(other.m_Program)){
		other.m_Program = 0;
	}

	ShaderProgram& ShaderProgram::operator=(ShaderProgram&& other) noexcept {
		m_Program = std::move(other.m_Program);
		other.m_Program = 0;

		return *this;
	}

	void ShaderProgram::use() {
		m_NextUnit = 0;
		
		if (this == m_ActiveProgram) {
			return;
		}
		glUseProgram(m_Program);
		m_ActiveProgram = this;
	}

	// Basic uniforms
	void ShaderProgram::upload(const std::string& variableName, const int value) {
		glUniform1i(glGetUniformLocation(m_ActiveProgram->m_Program, variableName.c_str()), value);
	}

	void ShaderProgram::upload(const std::string& variableName, const float value) {
		glUniform1f(glGetUniformLocation(m_ActiveProgram->m_Program, variableName.c_str()), value);
	}

	void ShaderProgram::upload(const std::string& variableName, const Matrix4f& matrix) {
		glUniformMatrix4fv(glGetUniformLocation(m_ActiveProgram->m_Program, variableName.c_str()), 1, GL_FALSE, &matrix.row1.x);
	}

	void ShaderProgram::upload(const std::string& variableName, const Vector3f& vector) {
		glUniform3fv(glGetUniformLocation(m_ActiveProgram->m_Program, variableName.c_str()), 1, &vector.x);
	}

	void ShaderProgram::upload(const std::string& variableName, const Vector4f& vector) {
		glUniform4fv(glGetUniformLocation(m_ActiveProgram->m_Program, variableName.c_str()), 1, &vector.x);
	}

	ShaderProgram* ShaderProgram::m_ActiveProgram{ nullptr };

	unsigned int ShaderProgram::m_NextUnit{ 0 };

	unsigned int ShaderProgram::getNextUnit() {
		const unsigned int unit = m_NextUnit;
		m_NextUnit++;
		return unit;
	}

	size_t ShaderProgram::GetHash() const {
		return m_PathHash;
	}
}

namespace ShaderProgramUploads {
	// Composite Uniforms
	void upload(const std::string& variableName, const Gem::Colour& colour) {
		Gem::ShaderProgram::upload(variableName, colour.toVec3()); // If need be can be changed to upload the alpha channel too.
	}

	void upload(const std::string& variableName, const std::vector<Gem::PointLight*>& pointLights) {
		upload("numberOfPointLights", (int)pointLights.size());
		unsigned int i{ 0 };
		for (const Gem::PointLight* pointLight : pointLights) {
			upload(variableName + '[' + std::to_string(i) + ']', *pointLight);
			i++;
		}
	}

	void upload(const std::string& variableName, const std::vector<Gem::PointLight>& pointLights) {
		upload("numberOfPointLights", (int)pointLights.size());
		unsigned int i{ 0 };
		for (const Gem::PointLight& pointLight : pointLights) {
			upload(variableName + '[' + std::to_string(i) + ']', pointLight);
			i++;
		}
	}

	void upload(const std::string& variableName, unsigned int unit, const std::vector<Gem::DirectionalLight*>& directionalLights) {
		upload("numberOfdirectionalLights", (int)directionalLights.size());
		unsigned int i{ 0 };
		for (const Gem::DirectionalLight* directionalLight : directionalLights) {
			upload(variableName + '[' + std::to_string(i) + ']', unit + i, *directionalLight);
			i++;
		}
	}

	void upload(const std::string& variableName, const std::vector<Gem::DirectionalLight*>& directionalLights) {
		const int unit = (int)Gem::ShaderProgram::getNextUnit();

		upload(variableName, unit, directionalLights);
	}

	void upload(const std::string& variableName, const std::vector<Gem::DirectionalLight>& directionalLights) {
		upload("numberOfdirectionalLights", (int)directionalLights.size());
		unsigned int i{ 0 };
		for (const Gem::DirectionalLight& directionalLight : directionalLights) {
			upload(variableName + '[' + std::to_string(i) + ']', directionalLight);
			i++;
		}
	}

	void upload(const std::string& variableName, const std::vector<Gem::Ptr<Gem::PointLight>>& pointLights) {
		upload("numberOfPointLights", (int)pointLights.size());
		unsigned int i{ 0 };
		for (const Gem::Ptr<Gem::PointLight>& pointLight : pointLights) {
			upload(variableName + '[' + std::to_string(i) + ']', *pointLight);
			i++;
		}
	}

	void upload(const std::string& variableName, const std::vector<Gem::Ptr<Gem::DirectionalLight>>& directionalLights) {
		upload("numberOfdirectionalLights", (int)directionalLights.size());
		unsigned int i{ 0 };
		for (const Gem::Ptr<Gem::DirectionalLight>& directionalLight : directionalLights) {
			upload(variableName + '[' + std::to_string(i) + ']', *directionalLight);
			i++;
		}
	}

	void upload(const std::string& variableName, unsigned int unit, const Gem::Texture& texture) {
		Gem::Texture::activateUnit(unit);
		texture.bind();
		Gem::ShaderProgram::upload(variableName, (int)unit);
	}

	void upload(const std::string& variableName, const Gem::Texture& texture) {
		const int unit = (int)Gem::ShaderProgram::getNextUnit();
		upload(variableName, unit, texture);
	}

	void upload(const std::string& variableName, unsigned int unit, const Gem::Cubemap& cubeMap) {
		Gem::Cubemap::activateUnit(unit);
		cubeMap.bind();
		Gem::ShaderProgram::upload(variableName, (int)unit);
	}

	void upload(const std::string& variableName, const Gem::Cubemap& cubeMap) {
		const int unit = (int)Gem::ShaderProgram::getNextUnit();
		upload(variableName, unit, cubeMap);
	}

	void upload(const std::string& variableName, const Gem::PointLight& pointLight) {
		Gem::ShaderProgram::upload(variableName + ".position", pointLight.position);

		Gem::ShaderProgram::upload(variableName + ".ambient", pointLight.ambient);
		Gem::ShaderProgram::upload(variableName + ".diffuse", pointLight.diffuse);
		Gem::ShaderProgram::upload(variableName + ".specular", pointLight.specular);

		Gem::ShaderProgram::upload(variableName + ".constant", pointLight.constant);
		Gem::ShaderProgram::upload(variableName + ".linear", pointLight.linear);
		Gem::ShaderProgram::upload(variableName + ".quadratic", pointLight.quadratic);
	}

	void upload(const std::string& variableName, unsigned int unit, const Gem::DirectionalLight& directionalLight) {
		Gem::ShaderProgram::upload(variableName + ".direction", directionalLight.direction);

		Gem::ShaderProgram::upload(variableName + ".ambient", directionalLight.ambient);
		Gem::ShaderProgram::upload(variableName + ".diffuse", directionalLight.diffuse);
		Gem::ShaderProgram::upload(variableName + ".specular", directionalLight.specular);
	}

	void upload(const std::string& variableName, const Gem::DirectionalLight& directionalLight) {
		Gem::ShaderProgram::upload(variableName + ".direction", directionalLight.direction);

		Gem::ShaderProgram::upload(variableName + ".ambient", directionalLight.ambient);
		Gem::ShaderProgram::upload(variableName + ".diffuse", directionalLight.diffuse);
		Gem::ShaderProgram::upload(variableName + ".specular", directionalLight.specular);
	}

	void upload(const std::string& variableName, const int value) {
		Gem::ShaderProgram::upload(variableName, value);
	}

	void upload(const std::string& variableName, const float value) {
		Gem::ShaderProgram::upload(variableName, value);
	}

	void upload(const std::string& variableName, const Gem::Matrix4f& matrix) {
		Gem::ShaderProgram::upload(variableName, matrix);
	}

	void upload(const std::string& variableName, const Gem::Vector3f& vector) {
		Gem::ShaderProgram::upload(variableName, vector);
	}

	void upload(const std::string& variableName, const Gem::Vector4f& vector) {
		Gem::ShaderProgram::upload(variableName, vector);
	}
}