#include "ShaderProgram.h"
#include "Log.h"
#include "Shaders/Uniforms/UniformSet.h"

namespace Ruby {
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
			LOG("Shader program failed to link.\n" + std::string(infoLog), Lazuli::LogLevel::ERROR);
		}
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
			LOG("Shader program failed to link.\n" + std::string(infoLog), Lazuli::LogLevel::ERROR);
		}
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

	void ShaderProgram::upload(const std::string& variableName, const Malachite::Matrix4f& matrix) {
		glUniformMatrix4fv(glGetUniformLocation(m_ActiveProgram->m_Program, variableName.c_str()), 1, GL_FALSE, &matrix.row1.x);
	}

	void ShaderProgram::upload(const std::string& variableName, const Malachite::Vector3f& vector) {
		glUniform3fv(glGetUniformLocation(m_ActiveProgram->m_Program, variableName.c_str()), 1, &vector.x);
	}

	void ShaderProgram::upload(const std::string& variableName, const Malachite::Vector4f& vector) {
		glUniform4fv(glGetUniformLocation(m_ActiveProgram->m_Program, variableName.c_str()), 1, &vector.x);
	}

	ShaderProgram* ShaderProgram::m_ActiveProgram{ nullptr };

	unsigned int ShaderProgram::m_NextUnit{ 0 };

	unsigned int ShaderProgram::getNextUnit() {
		const unsigned int unit = m_NextUnit;
		m_NextUnit++;
		return unit;
	}
}

namespace ShaderProgramUploads {
	// Composite Uniforms
	void upload(const std::string& variableName, const Ruby::Colour& colour) {
		Ruby::ShaderProgram::upload(variableName, colour.toVec3()); // If need be can be changed to upload the alpha channel too.
	}

	void upload(const std::string& variableName, const std::vector<Ruby::PointLight*>& pointLights) {
		upload("numberOfPointLights", (int)pointLights.size());
		unsigned int i{ 0 };
		for (const Ruby::PointLight* pointLight : pointLights) {
			upload(variableName + '[' + std::to_string(i) + ']', *pointLight);
			i++;
		}
	}

	void upload(const std::string& variableName, const std::vector<Ruby::PointLight>& pointLights) {
		upload("numberOfPointLights", (int)pointLights.size());
		unsigned int i{ 0 };
		for (const Ruby::PointLight& pointLight : pointLights) {
			upload(variableName + '[' + std::to_string(i) + ']', pointLight);
			i++;
		}
	}

	void upload(const std::string& variableName, unsigned int unit, const std::vector<Ruby::DirectionalLight*>& directionalLights) {
		upload("numberOfdirectionalLights", (int)directionalLights.size());
		unsigned int i{ 0 };
		for (const Ruby::DirectionalLight* directionalLight : directionalLights) {
			upload(variableName + '[' + std::to_string(i) + ']', unit + i, *directionalLight);
			i++;
		}
	}

	void upload(const std::string& variableName, const std::vector<Ruby::DirectionalLight*>& directionalLights) {
		const int unit = (int)Ruby::ShaderProgram::getNextUnit();

		upload(variableName, unit, directionalLights);
	}

	void upload(const std::string& variableName, const std::vector<Ruby::DirectionalLight>& directionalLights) {
		upload("numberOfdirectionalLights", (int)directionalLights.size());
		unsigned int i{ 0 };
		for (const Ruby::DirectionalLight& directionalLight : directionalLights) {
			upload(variableName + '[' + std::to_string(i) + ']', directionalLight);
			i++;
		}
	}

	void upload(const std::string& variableName, unsigned int unit, const Ruby::Texture& texture) {
		Ruby::Texture::activateUnit(unit);
		texture.bind();
		Ruby::ShaderProgram::upload(variableName, (int)unit);
	}

	void upload(const std::string& variableName, const Ruby::Texture& texture) {
		const int unit = (int)Ruby::ShaderProgram::getNextUnit();
		upload(variableName, unit, texture);
	}

	// void upload(const std::string& variableName, unsigned int unit, const Ruby::BufferTexture& texture) {
	// 	Ruby::Texture::activateUnit(unit);
	// 	texture.bind();
	// 	Ruby::ShaderProgram::upload(variableName, (int)unit);
	// }

	void upload(const std::string& variableName, unsigned int unit, const Ruby::Cubemap& cubeMap) {
		Ruby::Cubemap::activateUnit(unit);
		cubeMap.bind();
		Ruby::ShaderProgram::upload(variableName, (int)unit);
	}

	void upload(const std::string& variableName, const Ruby::Cubemap& cubeMap) {
		const int unit = (int)Ruby::ShaderProgram::getNextUnit();
		upload(variableName, unit, cubeMap);
	}

	void upload(const std::string& variableName, const Ruby::PointLight& pointLight) {
		Ruby::ShaderProgram::upload(variableName + ".position", pointLight.position);

		Ruby::ShaderProgram::upload(variableName + ".ambient", pointLight.ambient);
		Ruby::ShaderProgram::upload(variableName + ".diffuse", pointLight.diffuse);
		Ruby::ShaderProgram::upload(variableName + ".specular", pointLight.specular);

		Ruby::ShaderProgram::upload(variableName + ".constant", pointLight.constant);
		Ruby::ShaderProgram::upload(variableName + ".linear", pointLight.linear);
		Ruby::ShaderProgram::upload(variableName + ".quadratic", pointLight.quadratic);
	}

	void upload(const std::string& variableName, unsigned int unit, const Ruby::DirectionalLight& directionalLight) {
		Ruby::ShaderProgram::upload(variableName + ".direction", directionalLight.direction);

		Ruby::ShaderProgram::upload(variableName + ".ambient", directionalLight.ambient);
		Ruby::ShaderProgram::upload(variableName + ".diffuse", directionalLight.diffuse);
		Ruby::ShaderProgram::upload(variableName + ".specular", directionalLight.specular);
	}

	void upload(const std::string& variableName, const Ruby::DirectionalLight& directionalLight) {
		Ruby::ShaderProgram::upload(variableName + ".direction", directionalLight.direction);

		Ruby::ShaderProgram::upload(variableName + ".ambient", directionalLight.ambient);
		Ruby::ShaderProgram::upload(variableName + ".diffuse", directionalLight.diffuse);
		Ruby::ShaderProgram::upload(variableName + ".specular", directionalLight.specular);
	}

	void upload(const std::string& variableName, const int value) {
		Ruby::ShaderProgram::upload(variableName, value);
	}

	void upload(const std::string& variableName, const float value) {
		Ruby::ShaderProgram::upload(variableName, value);
	}

	void upload(const std::string& variableName, const Malachite::Matrix4f& matrix) {
		Ruby::ShaderProgram::upload(variableName, matrix);
	}

	void upload(const std::string& variableName, const Malachite::Vector3f& vector) {
		Ruby::ShaderProgram::upload(variableName, vector);
	}

	void upload(const std::string& variableName, const Malachite::Vector4f& vector) {
		Ruby::ShaderProgram::upload(variableName, vector);
	}
}