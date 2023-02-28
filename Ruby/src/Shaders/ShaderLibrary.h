#pragma once

#include <map>

#include "ShaderProgram.h"

namespace Ruby {
	class ShaderLibrary { //TODO rename to ShaderRegister
	public:
		static ShaderLibrary& Get();

		ShaderLibrary(const ShaderLibrary& other) = delete;
		ShaderLibrary& operator=(const ShaderLibrary& other) = delete;

		ShaderProgram shadowPhongShader;
		ShaderProgram solidShader;
		ShaderProgram directionalDepthShader;
		ShaderProgram imageShader;
		ShaderProgram skyBoxShader;
		ShaderProgram phongShader;
		ShaderProgram screenQuadShader;

		ShaderHandle LoadShader(const std::string& vertexPath, const std::string& fragmentPath);

		inline ShaderProgram& operator[](const ShaderHandle& handle) {
			return *m_Shaders[handle];
		}

	private:
		ShaderLibrary();

		static ShaderProgram CreateProgram(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);

		std::map<ShaderHandle, Celestite::Ptr<ShaderProgram>> m_Shaders;
	};
}