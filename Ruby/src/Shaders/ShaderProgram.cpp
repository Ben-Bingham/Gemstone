#include "ShaderProgram.h"
#include "Log.h"

namespace Ruby {
	ShaderProgram::ShaderProgram(ShaderProgram&& other) noexcept
		: m_Program(std::move(other.m_Program)),
		m_Attributes(std::move(other.m_Attributes)) {
		other.m_Program = 0;
	}

	ShaderProgram& ShaderProgram::operator=(ShaderProgram&& other) noexcept {
		m_Program = std::move(other.m_Program);
		other.m_Program = 0;

		m_Attributes = std::move(other.m_Attributes);
		return *this;
	}

	void ShaderProgram::use() {
		glUseProgram(m_Program);
		activePorgram = this;
	}

	std::vector<Attribute> ShaderProgram::getAttributes() const {
		return m_Attributes;
	}

	ShaderProgram::ShaderProgram(const VertexShader& vertexShader, const FragmentShader& fragmentShader, const std::vector<Attribute>& attributes) 
		: m_Attributes(attributes) {
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
	}

	ShaderProgram::ShaderProgram(const VertexShader& vertexShader, const GeometryShader& geometryShader, const FragmentShader& fragmentShader, const std::vector<Attribute>& attributes)
		: m_Attributes(attributes) {
		int success;
		char infoLog[512];

		m_Program = glCreateProgram();

		glAttachShader(m_Program, vertexShader.getShader());
		glAttachShader(m_Program, geometryShader.getShader());
		glAttachShader(m_Program, fragmentShader.getShader());

		glLinkProgram(m_Program);

		glGetProgramiv(m_Program, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(m_Program, 512, NULL, infoLog);
			LOG("Shader program failed to link.\n" + std::string(infoLog), Lazuli::LogLevel::ERROR);
		}
	}

	// Basic uniforms
	void ShaderProgram::upload(const std::string& variableName, const int value) {
		glUniform1i(glGetUniformLocation(activePorgram->m_Program, variableName.c_str()), value);
	}

	void ShaderProgram::upload(const std::string& variableName, const float value) {
		glUniform1f(glGetUniformLocation(activePorgram->m_Program, variableName.c_str()), value);
	}

	void ShaderProgram::upload(const std::string& variableName, const Malachite::Matrix4f& matrix) {
		glUniformMatrix4fv(glGetUniformLocation(activePorgram->m_Program, variableName.c_str()), 1, GL_FALSE, &matrix.row1.x);
	}

	void ShaderProgram::upload(const std::string& variableName, const Malachite::Vector3f& vector) {
		glUniform3fv(glGetUniformLocation(activePorgram->m_Program, variableName.c_str()), 1, &vector.x);
	}

	void ShaderProgram::upload(const std::string& variableName, const Malachite::Vector4f& vector) {
		glUniform4fv(glGetUniformLocation(activePorgram->m_Program, variableName.c_str()), 1, &vector.x);
	}

	// Composite Uniforms
	void ShaderProgram::upload(const std::string& variableName, const std::vector<PointLight*>& pointLights) {
		activePorgram->upload("numberOfPointLights", (int)pointLights.size());
		unsigned int i{ 0 };
		for (const PointLight* pointLight : pointLights) {
			activePorgram->upload(variableName + '[' + std::to_string(i) + ']', *pointLight);
			i++;
		}
	}

	void ShaderProgram::upload(const std::string& variableName, unsigned int unit, const std::vector<DirectionalLight*>& directionalLights) {
		activePorgram->upload("numberOfdirectionalLights", (int)directionalLights.size());
		unsigned int i{ 0 };
		for (const DirectionalLight* directionalLight : directionalLights) {
			activePorgram->upload(variableName + '[' + std::to_string(i) + ']', unit + i, *directionalLight);
			i++;
		}
	}

	void ShaderProgram::upload(const std::string& variableName, unsigned int unit, const Texture& texture) {
		texture.activateUnit(unit);
		texture.bind();
		activePorgram->upload(variableName, (int)unit);
	}

	void ShaderProgram::upload(const std::string& variableName, unsigned int unit, const BufferTexture& texture) {
		texture.activateUnit(unit);
		texture.bind();
		activePorgram->upload(variableName, (int)unit);
	}

	void ShaderProgram::upload(const std::string& variableName, unsigned int unit, const Cubemap& cubemap) {
		cubemap.activateUnit(unit);
		cubemap.bind();
		activePorgram->upload(variableName, (int)unit);
	}

	void ShaderProgram::upload(const std::string& variableName, unsigned int startUnit, const PhongMaterial& material) {
		activePorgram->upload(variableName + ".diffuse", startUnit, *material.diffuse);
		activePorgram->upload(variableName + ".specular", startUnit + 1, *material.specular);
		activePorgram->upload(variableName + ".shininess", material.shininess);
	}

	void ShaderProgram::upload(const std::string& variableName, const PointLight& pointLight) {
		activePorgram->upload(variableName + ".position", pointLight.position);

		activePorgram->upload(variableName + ".ambient", pointLight.ambient);
		activePorgram->upload(variableName + ".diffuse", pointLight.diffuse);
		activePorgram->upload(variableName + ".specular", pointLight.specular);

		activePorgram->upload(variableName + ".constant", pointLight.constant);
		activePorgram->upload(variableName + ".linear", pointLight.linear);
		activePorgram->upload(variableName + ".quadratic", pointLight.quadratic);
	}

	void ShaderProgram::upload(const std::string& variableName, unsigned int unit, const DirectionalLight& directionalLight) {
		activePorgram->upload(variableName + ".direction", directionalLight.direction);

		activePorgram->upload(variableName + ".ambient", directionalLight.ambient);
		activePorgram->upload(variableName + ".diffuse", directionalLight.diffuse);
		activePorgram->upload(variableName + ".specular", directionalLight.specular);
	}

	ShaderProgram* ShaderProgram::activePorgram{ nullptr };
}