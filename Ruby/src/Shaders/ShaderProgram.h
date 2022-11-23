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
#include "OpenGL objects/BufferTexture.h"

#include "OpenGL objects/VertexAttributeObject.h"

namespace Ruby {
	class ShaderProgram {
	public:
		ShaderProgram(const VertexShader& vertexShader, const FragmentShader& fragmentShader, const std::vector<Attribute>& attributes);
		ShaderProgram(const VertexShader& vertexShader, const GeometryShader& geometryShader, const FragmentShader& fragmentShader, const std::vector<Attribute>& attributes);
		
		ShaderProgram(ShaderProgram&) = delete;
		ShaderProgram& operator=(ShaderProgram&) = delete;
		ShaderProgram(ShaderProgram&& other) noexcept;
		ShaderProgram& operator=(ShaderProgram&& other) noexcept;
		~ShaderProgram() { glDeleteProgram(m_Program); }

		struct UniformData {
			enum class DataType {
				VECTOR_4F,
				VECTOR_3F,
				VECTOR_2F,

				MATRIX_4X4F,
				MATRIX_4X3F,
				MATRIX_3X3F,

				FLOAT,
				INT,

				TEXTURE_2D,
				TEXTURE_CUBE
			};
			DataType dataType;
		};

		void use();

		std::vector<Attribute> getAttributes() const;

		// Basic uniforms Static Versions
		static void upload(const std::string& variableName, const int value);
		static void upload(const std::string& variableName, const float value);
		static void upload(const std::string& variableName, const Malachite::Matrix4f& matrix);
		static void upload(const std::string& variableName, const Malachite::Vector3f& vector);
		static void upload(const std::string& variableName, const Malachite::Vector4f& vector);

		// Advanced uniforms
		static void upload(const std::string& variableName, const PointLight& pointLight);
		static void upload(const std::string& variableName, unsigned int unit, const DirectionalLight& directionalLight);
		static void upload(const std::string& variableName, const std::vector<PointLight*>& pointLights);
		static void upload(const std::string& variableName, unsigned int unit, const std::vector<DirectionalLight*>& directionalLights);
		static void upload(const std::string& variableName, unsigned int unit, const Texture& texture);
		static void upload(const std::string& variableName, unsigned int unit, const BufferTexture& texture);
		static void upload(const std::string& variableName, unsigned int unit, const Cubemap& cubemap);
		static void upload(const std::string& variableName, unsigned int startUnit, const PhongMaterial& material);

	private:
		unsigned int m_Program;
		std::vector<Attribute> m_Attributes;
		static ShaderProgram* activePorgram;
	};
}