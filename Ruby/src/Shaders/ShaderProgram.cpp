#include "ShaderProgram.h"
#include "Log.h"
#include "Shaders/Uniforms/UniformSet.h"

namespace Ruby {
	ShaderProgram::ShaderProgram(const VertexShader& vertexShader, const FragmentShader& fragmentShader)
		: m_LayoutData(vertexShader.getLayout()) {
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

	ShaderProgram::ShaderProgram(const VertexShader& vertexShader, const GeometryShader& geometryShader, const FragmentShader& fragmentShader)
		: m_LayoutData(vertexShader.getLayout()) {
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


	ShaderProgram::ShaderProgram(ShaderProgram&& other) noexcept
		: m_Program(std::move(other.m_Program)),
		m_LayoutData(std::move(other.m_LayoutData)) {
		other.m_Program = 0;
	}

	ShaderProgram& ShaderProgram::operator=(ShaderProgram&& other) noexcept {
		m_Program = std::move(other.m_Program);
		other.m_Program = 0;

		m_LayoutData = std::move(other.m_LayoutData);
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

	VertexShader::LayoutData ShaderProgram::getLayout() {
		return m_LayoutData;
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

	// Composite Uniforms
	void ShaderProgram::upload(const std::string& variableName, const Colour& colour) {
		m_ActiveProgram->upload(variableName, colour.toVec3()); // If need be can be changed to upload the alpha channel too.
	}


	void ShaderProgram::upload(const std::string& variableName, const std::vector<PointLight*>& pointLights) {
		m_ActiveProgram->upload("numberOfPointLights", (int)pointLights.size());
		unsigned int i{ 0 };
		for (const PointLight* pointLight : pointLights) {
			m_ActiveProgram->upload(variableName + '[' + std::to_string(i) + ']', *pointLight);
			i++;
		}
	}

	void ShaderProgram::upload(const std::string& variableName, const std::vector<PointLight>& pointLights) {
		m_ActiveProgram->upload("numberOfPointLights", (int)pointLights.size());
		unsigned int i{ 0 };
		for (const PointLight pointLight : pointLights) {
			m_ActiveProgram->upload(variableName + '[' + std::to_string(i) + ']', pointLight);
			i++;
		}
	}

	void ShaderProgram::upload(const std::string& variableName, unsigned int unit, const std::vector<DirectionalLight*>& directionalLights) {
		m_ActiveProgram->upload("numberOfdirectionalLights", (int)directionalLights.size());
		unsigned int i{ 0 };
		for (const DirectionalLight* directionalLight : directionalLights) {
			m_ActiveProgram->upload(variableName + '[' + std::to_string(i) + ']', unit + i, *directionalLight);
			i++;
		}
	}

	void ShaderProgram::upload(const std::string& variableName, const std::vector<DirectionalLight>& directionalLights) {
		m_ActiveProgram->upload("numberOfdirectionalLights", (int)directionalLights.size());
		unsigned int i{ 0 };
		for (const DirectionalLight directionalLight : directionalLights) {
			m_ActiveProgram->upload(variableName + '[' + std::to_string(i) + ']', directionalLight);
			i++;
		}
	}

	void ShaderProgram::upload(const std::string& variableName, unsigned int unit, const Texture& texture) {
		texture.activateUnit(unit);
		texture.bind();
		m_ActiveProgram->upload(variableName, (int)unit);
	}

	void ShaderProgram::upload(const std::string& variableName, const Texture& texture) {
		const int unit = (int)getNextUnit();
		upload(variableName, unit, texture);
	}


	void ShaderProgram::upload(const std::string& variableName, unsigned int unit, const BufferTexture& texture) {
		texture.activateUnit(unit);
		texture.bind();
		m_ActiveProgram->upload(variableName, (int)unit);
	}

	void ShaderProgram::upload(const std::string& variableName, unsigned int unit, const Cubemap& cubemap) {
		cubemap.activateUnit(unit);
		cubemap.bind();
		m_ActiveProgram->upload(variableName, (int)unit);
	}

	void ShaderProgram::upload(const std::string& variableName, const Cubemap& cubemap) {
		const int unit = (int)getNextUnit();
		upload(variableName, unit, cubemap);
	}

	void ShaderProgram::upload(const std::string& variableName, const PointLight& pointLight) {
		m_ActiveProgram->upload(variableName + ".position", pointLight.position);

		m_ActiveProgram->upload(variableName + ".ambient", pointLight.ambient);
		m_ActiveProgram->upload(variableName + ".diffuse", pointLight.diffuse);
		m_ActiveProgram->upload(variableName + ".specular", pointLight.specular);

		m_ActiveProgram->upload(variableName + ".constant", pointLight.constant);
		m_ActiveProgram->upload(variableName + ".linear", pointLight.linear);
		m_ActiveProgram->upload(variableName + ".quadratic", pointLight.quadratic);
	}

	void ShaderProgram::upload(const std::string& variableName, unsigned int unit, const DirectionalLight& directionalLight) {
		m_ActiveProgram->upload(variableName + ".direction", directionalLight.direction);

		m_ActiveProgram->upload(variableName + ".ambient", directionalLight.ambient);
		m_ActiveProgram->upload(variableName + ".diffuse", directionalLight.diffuse);
		m_ActiveProgram->upload(variableName + ".specular", directionalLight.specular);
	}

	void ShaderProgram::upload(const std::string& variableName, const DirectionalLight& directionalLight) {
		m_ActiveProgram->upload(variableName + ".direction", directionalLight.direction);

		m_ActiveProgram->upload(variableName + ".ambient", directionalLight.ambient);
		m_ActiveProgram->upload(variableName + ".diffuse", directionalLight.diffuse);
		m_ActiveProgram->upload(variableName + ".specular", directionalLight.specular);
	}

	ShaderProgram* ShaderProgram::m_ActiveProgram{ nullptr };

	unsigned int ShaderProgram::m_NextUnit{ 0 };

	unsigned int ShaderProgram::getNextUnit() {
		const unsigned int unit = m_NextUnit;
		m_NextUnit++;
		return unit;
	}

}