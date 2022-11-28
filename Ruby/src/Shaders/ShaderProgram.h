#pragma once
#include <vector>

#include <GL/glew.h>

#include "Utility/Colour.h"
#include "VertexShader.h"
#include "FragmentShader.h"
#include "GeometryShader.h"
#include "Vector.h"
#include "Matrix.h"
#include "Lights.h"
#include "OpenGl objects/Texture.h"
#include "OpenGL objects/Cubemap.h"
#include "OpenGL objects/BufferTexture.h"

namespace Ruby {
	template<typename...T>
	class UniformSet;

	class ShaderProgram {
	public:
		ShaderProgram(const VertexShader& vertexShader, const FragmentShader& fragmentShader);
		ShaderProgram(const VertexShader& vertexShader, const GeometryShader& geometryShader, const FragmentShader& fragmentShader);
		
		ShaderProgram(ShaderProgram&) = delete;
		ShaderProgram& operator=(ShaderProgram&) = delete;
		ShaderProgram(ShaderProgram&& other) noexcept;
		ShaderProgram& operator=(ShaderProgram&& other) noexcept;
		~ShaderProgram() { glDeleteProgram(m_Program); }

		void use();

		VertexShader::LayoutData getLayout() const;

		// Basic uniforms Static Versions
		static void upload(const std::string& variableName, const int value);
		static void upload(const std::string& variableName, const float value);
		static void upload(const std::string& variableName, const Malachite::Matrix4f& matrix);
		static void upload(const std::string& variableName, const Malachite::Vector3f& vector);
		static void upload(const std::string& variableName, const Malachite::Vector4f& vector);

		// Advanced uniforms
		static void upload(const std::string& variableName, const Colour& colour);
		static void upload(const std::string& variableName, const PointLight& pointLight);
		static void upload(const std::string& variableName, const DirectionalLight& directionalLight);
		static void upload(const std::string& variableName, const std::vector<PointLight*>& pointLights);
		static void upload(const std::string& variableName, const std::vector<PointLight>& pointLights);
		static void upload(const std::string& variableName, const std::vector<DirectionalLight*>& directionalLights);
		static void upload(const std::string& variableName, const std::vector<DirectionalLight>& directionalLights);
		static void upload(const std::string& variableName, const Texture& texture);
		static void upload(const std::string& variableName, const Cubemap& cubeMap);

	private:
		// Private Uniforms
		static void upload(const std::string& variableName, unsigned int unit, const DirectionalLight& directionalLight);
		static void upload(const std::string& variableName, unsigned int unit, const std::vector<DirectionalLight*>& directionalLights);
		static void upload(const std::string& variableName, unsigned int unit, const Texture& texture);
		static void upload(const std::string& variableName, unsigned int unit, const BufferTexture& texture);
		static void upload(const std::string& variableName, unsigned int unit, const Cubemap& cubeMap);

		unsigned int m_Program;

		VertexShader::LayoutData m_LayoutData;

		static ShaderProgram* m_ActiveProgram;

		static unsigned int m_NextUnit;

		static unsigned int getNextUnit();
	};
}