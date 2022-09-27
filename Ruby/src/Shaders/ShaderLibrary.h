#pragma once

#include "ShaderProgram.h"

namespace Ruby {
	class ShaderLibrary {
	public:
		ShaderLibrary()
			: phongShader(shaderInit("..\\Ruby\\assets\\shaders\\Phong.vert", "..\\Ruby\\assets\\shaders\\Phong.frag", std::vector<Ruby::Attribute>{ 3, 3, 2 })),
			  solidShader(shaderInit("..\\Ruby\\assets\\shaders\\Solid.vert", "..\\Ruby\\assets\\shaders\\Solid.frag", std::vector<Ruby::Attribute>{ 3 })),
			  directionalDepthShader(shaderInit("..\\Ruby\\assets\\shaders\\DirectionalDepth.vert", "..\\Ruby\\assets\\shaders\\DirectionalDepth.frag", std::vector<Ruby::Attribute>{ 3, 3, 2 })),
			  imageShader(shaderInit("..\\Ruby\\assets\\shaders\\Image.vert", "..\\Ruby\\assets\\shaders\\Image.frag", std::vector<Ruby::Attribute>{ 3, 2 })),
			  skyboxShader(shaderInit("..\\Ruby\\assets\\shaders\\Skybox.vert", "..\\Ruby\\assets\\shaders\\Skybox.frag", std::vector<Ruby::Attribute>{ 3 }))
		{}

		ShaderProgram phongShader;
		ShaderProgram solidShader;
		ShaderProgram directionalDepthShader;
		ShaderProgram imageShader;
		ShaderProgram skyboxShader;

	private:
		ShaderProgram shaderInit(const std::string& vertexShaderPath, const std::string& fragmentShaderPath, const std::vector<Attribute>& attributes) {
			return ShaderProgram{ VertexShader{vertexShaderPath}, FragmentShader{fragmentShaderPath}, attributes };
		}
	};
}