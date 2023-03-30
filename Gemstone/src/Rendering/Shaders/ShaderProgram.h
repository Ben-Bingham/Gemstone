#pragma once
#include <vector>

#include <GL/glew.h>

#include "VertexShader.h"
#include "FragmentShader.h"
#include "GeometryShader.h"

#include "Rendering/Lights.h"
#include "Rendering/OpenGL objects/BufferTexture.h"
#include "Rendering/OpenGL objects/Cubemap.h"
#include "Rendering/OpenGL objects/Texture.h"

#include "Utility/Colour.h"
#include "Utility/Pointer.h"

namespace Gem {
	template<typename...T>
	class UniformSet;

	using ShaderHandle = size_t;

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
		static void upload(const std::string& variableName, const Matrix4f& matrix);
		static void upload(const std::string& variableName, const Vector3f& vector);
		static void upload(const std::string& variableName, const Vector4f& vector);

		static unsigned int getNextUnit();

		[[nodiscard]] ShaderHandle GetHash() const;

	private:
		unsigned int m_Program;

		static ShaderProgram* m_ActiveProgram;

		static unsigned int m_NextUnit;

		ShaderHandle m_PathHash{ 0 };
	};
}

namespace ShaderProgramUploads {
	void upload(const std::string& variableName, const int value);
	void upload(const std::string& variableName, const float value);
	void upload(const std::string& variableName, const Gem::Matrix4f& matrix);
	void upload(const std::string& variableName, const Gem::Vector3f& vector);
	void upload(const std::string& variableName, const Gem::Vector4f& vector);

	void upload(const std::string& variableName, const Gem::Colour& colour);
	void upload(const std::string& variableName, const Gem::PointLight& pointLight);
	void upload(const std::string& variableName, const Gem::DirectionalLight& directionalLight);
	void upload(const std::string& variableName, const std::vector<Gem::PointLight*>& pointLights);
	void upload(const std::string& variableName, const std::vector<Gem::PointLight>& pointLights);
	void upload(const std::string& variableName, const std::vector<Gem::Ptr<Gem::PointLight>>& pointLights);
	void upload(const std::string& variableName, const std::vector<Gem::DirectionalLight*>& directionalLights);
	void upload(const std::string& variableName, const std::vector<Gem::DirectionalLight>& directionalLights);
	void upload(const std::string& variableName, const std::vector<Gem::Ptr<Gem::DirectionalLight>>& directionalLights);
	void upload(const std::string& variableName, const Gem::Texture& texture);
	void upload(const std::string& variableName, const Gem::Cubemap& cubeMap);

	void upload(const std::string& variableName, unsigned int unit, const Gem::DirectionalLight& directionalLight);
	void upload(const std::string& variableName, unsigned int unit, const std::vector<Gem::DirectionalLight*>& directionalLights);
	void upload(const std::string& variableName, unsigned int unit, const Gem::Texture& texture);
	void upload(const std::string& variableName, unsigned int unit, const Gem::Cubemap& cubeMap);

	template<typename T>
	void upload(const std::string& variableName, unsigned int unit, const Gem::BufferTexture<T>& buffer) {
		buffer.Bind();
		Gem::Texture::activateUnit(unit);
		Gem::ShaderProgram::upload(variableName, (int)unit);
	}

	template<typename T>
	void upload(const std::string& variableName, const Gem::BufferTexture<T>& buffer) {
		const int unit = (int)Gem::ShaderProgram::getNextUnit();
		upload(variableName, unit, buffer);
	}

	template<typename T>
	void upload(const std::string& variableName, unsigned int unit, const Gem::Ptr<Gem::BufferTexture<T>>& buffer) {
		upload(variableName, unit, *buffer);
	}

	template<typename T>
	void upload(const std::string& variableName, const Gem::Ptr<Gem::BufferTexture<T>>& buffer) {
		upload(variableName, *buffer);
	}
}