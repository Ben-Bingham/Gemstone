#pragma once

#include "ShaderProgram.h"

namespace Ruby {
	class ShaderLibrary {
	public:
		ShaderLibrary()
			: phongShader(shaderInit("..\\Ruby\\assets\\shaders\\Phong.vert", "..\\Ruby\\assets\\shaders\\Phong.frag", std::vector<Ruby::Attribute>{ 3, 3, 2 })),
			  solidShader(shaderInit("..\\Ruby\\assets\\shaders\\Solid.vert", "..\\Ruby\\assets\\shaders\\Solid.frag", std::vector<Ruby::Attribute>{ 3 })) {}

		ShaderProgram phongShader;
		ShaderProgram solidShader;

	private:
		ShaderProgram shaderInit(const std::string& vertexShaderPath, const std::string& fragmentShaderPath, const std::vector<Attribute>& attributes) {
			return ShaderProgram{ VertexShader{vertexShaderPath}, FragmentShader{fragmentShaderPath}, attributes };
		}
	};
}