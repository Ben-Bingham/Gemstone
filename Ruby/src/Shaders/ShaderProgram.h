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

		// Basic uniforms Static Versions
		static void upload(const std::string& variableName, const int value);
		static void upload(const std::string& variableName, const float value);
		static void upload(const std::string& variableName, const Malachite::Matrix4f& matrix);
		static void upload(const std::string& variableName, const Malachite::Vector3f& vector);
		static void upload(const std::string& variableName, const Malachite::Vector4f& vector);

		static unsigned int getNextUnit();

	private:
		unsigned int m_Program;

		static ShaderProgram* m_ActiveProgram;

		static unsigned int m_NextUnit;

	};
}

namespace ShaderProgramUploads {
	void upload(const std::string& variableName, const int value);
	void upload(const std::string& variableName, const float value);
	void upload(const std::string& variableName, const Malachite::Matrix4f& matrix);
	void upload(const std::string& variableName, const Malachite::Vector3f& vector);
	void upload(const std::string& variableName, const Malachite::Vector4f& vector);

	void upload(const std::string& variableName, const Ruby::Colour& colour);
	void upload(const std::string& variableName, const Ruby::PointLight& pointLight);
	void upload(const std::string& variableName, const Ruby::DirectionalLight& directionalLight);
	void upload(const std::string& variableName, const std::vector<Ruby::PointLight*>& pointLights);
	void upload(const std::string& variableName, const std::vector<Ruby::PointLight>& pointLights);
	void upload(const std::string& variableName, const std::vector<Ruby::DirectionalLight*>& directionalLights);
	void upload(const std::string& variableName, const std::vector<Ruby::DirectionalLight>& directionalLights);
	void upload(const std::string& variableName, const Ruby::Texture& texture);
	void upload(const std::string& variableName, const Ruby::Cubemap& cubeMap);

	void upload(const std::string& variableName, unsigned int unit, const Ruby::DirectionalLight& directionalLight);
	void upload(const std::string& variableName, unsigned int unit, const std::vector<Ruby::DirectionalLight*>& directionalLights);
	void upload(const std::string& variableName, unsigned int unit, const Ruby::Texture& texture);
	// void upload(const std::string& variableName, unsigned int unit, const Ruby::BufferTexture& texture);
	void upload(const std::string& variableName, unsigned int unit, const Ruby::Cubemap& cubeMap);
}