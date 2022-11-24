#include "ShaderProgram.h"
#include "Log.h"

namespace Ruby {
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

		parseUniforms(vertexShader.getShaderSourceFile());
		parseUniforms(fragmentShader.getShaderSourceFile());
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

		parseUniforms(vertexShader.getShaderSourceFile());
		parseUniforms(geometryShader.getShaderSourceFile());
		parseUniforms(fragmentShader.getShaderSourceFile());
	}


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
		if (this == m_ActiveProgram) {
			return;
		}
		glUseProgram(m_Program);
		m_ActiveProgram = this;
	}

	std::vector<Attribute> ShaderProgram::getAttributes() const {
		return m_Attributes;
	}

	// Basic uniforms
	void ShaderProgram::upload(const std::string& variableName, const int value) {
#ifdef RUBY_DEBUG
		if (!m_ActiveProgram->m_Uniforms.contains(variableName)) {
			LOG("Uniform: " + variableName + " does not exist.", Lazuli::LogLevel::ERROR);
		}
#endif
		glUniform1i(glGetUniformLocation(m_ActiveProgram->m_Program, variableName.c_str()), value);
	}

	void ShaderProgram::upload(const std::string& variableName, const float value) {
#ifdef RUBY_DEBUG
		if (!m_ActiveProgram->m_Uniforms.contains(variableName)) {
			LOG("Uniform: " + variableName + " does not exist.", Lazuli::LogLevel::ERROR);
		}
#endif
		glUniform1f(glGetUniformLocation(m_ActiveProgram->m_Program, variableName.c_str()), value);
	}

	void ShaderProgram::upload(const std::string& variableName, const Malachite::Matrix4f& matrix) {
#ifdef RUBY_DEBUG
		if (!m_ActiveProgram->m_Uniforms.contains(variableName)) {
			LOG("Uniform: " + variableName + " does not exist.", Lazuli::LogLevel::ERROR);
		}
#endif
		glUniformMatrix4fv(glGetUniformLocation(m_ActiveProgram->m_Program, variableName.c_str()), 1, GL_FALSE, &matrix.row1.x);
	}

	void ShaderProgram::upload(const std::string& variableName, const Malachite::Vector3f& vector) {
#ifdef RUBY_DEBUG
		if (!m_ActiveProgram->m_Uniforms.contains(variableName)) {
			LOG("Uniform: " + variableName + " does not exist.", Lazuli::LogLevel::ERROR);
		}
#endif
		glUniform3fv(glGetUniformLocation(m_ActiveProgram->m_Program, variableName.c_str()), 1, &vector.x);
	}

	void ShaderProgram::upload(const std::string& variableName, const Malachite::Vector4f& vector) {
#ifdef RUBY_DEBUG
		if (!m_ActiveProgram->m_Uniforms.contains(variableName)) {
			LOG("Uniform: " + variableName + " does not exist.", Lazuli::LogLevel::ERROR);
		}
#endif
		glUniform4fv(glGetUniformLocation(m_ActiveProgram->m_Program, variableName.c_str()), 1, &vector.x);
	}

	// Composite Uniforms
	void ShaderProgram::upload(const std::string& variableName, const std::vector<PointLight*>& pointLights) {
		m_ActiveProgram->upload("numberOfPointLights", (int)pointLights.size());
		unsigned int i{ 0 };
		for (const PointLight* pointLight : pointLights) {
			m_ActiveProgram->upload(variableName + '[' + std::to_string(i) + ']', *pointLight);
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

	void ShaderProgram::upload(const std::string& variableName, unsigned int unit, const Texture& texture) {
		texture.activateUnit(unit);
		texture.bind();
		m_ActiveProgram->upload(variableName, (int)unit);
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

	void ShaderProgram::upload(const std::string& variableName, unsigned int startUnit, const PhongMaterial& material) {
		m_ActiveProgram->upload(variableName + ".diffuse", startUnit, *material.diffuse);
		m_ActiveProgram->upload(variableName + ".specular", startUnit + 1, *material.specular);
		m_ActiveProgram->upload(variableName + ".shininess", material.shininess);
	}

	void ShaderProgram::parseUniforms(const TextFile& textFile) {
		std::string content = textFile.getContent();
		std::string::size_type location = 0;
		std::vector<std::string> uniformStrings;

		while (true) {
			location = content.find("uniform", location);

			if (location > content.size()) {
				break;
			}

			std::string uniformString = "";
			while (content[location] != ';') {
				uniformString += content[location];
				location++;
			}
			uniformStrings.push_back(uniformString);
		}

		// Sample: "uniform mat4 model"
		for (std::string& uniform : uniformStrings) {
			std::string type;
			std::string name;

			std::string::size_type startOfType = uniform.find(' ');
			std::string::size_type endOfType = uniform.find(' ', startOfType + 1);

			type = uniform.substr(startOfType + 1, endOfType - startOfType - 1);

			name = uniform.substr(endOfType + 1);

			UniformType enumType = parseUniformType(type);
			std::unique_ptr<UniformDataElement> uniformDataElement;
			switch (enumType) {
			case UniformType::UNKNOWN:
			default:
				break;
			case UniformType::FLOAT: 
				uniformDataElement = std::make_unique<Uniform::Float>(name);
				break;
			case UniformType::INT:
				uniformDataElement = std::make_unique<Uniform::Int>(name);
				break;
			case UniformType::VECTOR_3F: 
				uniformDataElement = std::make_unique<Uniform::Vector3f>(name);
				break;
			case UniformType::VECTOR_4F: 
				uniformDataElement = std::make_unique<Uniform::Vector4f>(name);
				break;
			case UniformType::MATRIX_4X4F: 
				uniformDataElement = std::make_unique<Uniform::Matrix4x4f>(name);
				break;
			}

			m_Uniforms.add(uniformDataElement);
		}
	}

	UniformType ShaderProgram::parseUniformType(const std::string& type) {
		if (type == "float") {
			return UniformType::FLOAT;
		}
		if(type == "int") {
			return UniformType::INT;
		}
		if (type == "vec3") {
			return UniformType::VECTOR_3F;
		}
		if (type == "vec4") {
			return UniformType::VECTOR_4F;
		}
		if (type == "mat4") {
			return UniformType::MATRIX_4X4F;
		}
		return UniformType::UNKNOWN;
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

	ShaderProgram* ShaderProgram::m_ActiveProgram{ nullptr };
}