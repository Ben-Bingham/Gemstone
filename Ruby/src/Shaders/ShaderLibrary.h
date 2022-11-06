#pragma once

#include "ShaderProgram.h"

namespace Ruby {
	class ShaderLibrary {
	public:
		ShaderLibrary()
			: shadowPhongShader(shaderInit(std::string(RUBY_ASSETS) + "\\shaders\\ShadowPhong.vert", std::string(RUBY_ASSETS) + "\\shaders\\ShadowPhong.frag", std::vector<Ruby::Attribute>{ 3, 3, 2 })),
			  solidShader(shaderInit(std::string(RUBY_ASSETS) + "\\shaders\\Solid.vert", std::string(RUBY_ASSETS) + "\\shaders\\Solid.frag", std::vector<Ruby::Attribute>{ 3 })),
			  directionalDepthShader(shaderInit(std::string(RUBY_ASSETS) + "\\shaders\\DirectionalDepth.vert", std::string(RUBY_ASSETS) + "\\shaders\\DirectionalDepth.frag", std::vector<Ruby::Attribute>{ 3, 3, 2 })),
			  imageShader(shaderInit(std::string(RUBY_ASSETS) + "\\shaders\\Image.vert", std::string(RUBY_ASSETS) + "\\shaders\\Image.frag", std::vector<Ruby::Attribute>{ 3, 2 })),
			  skyboxShader(shaderInit(std::string(RUBY_ASSETS) + "\\shaders\\Skybox.vert", std::string(RUBY_ASSETS) + "\\shaders\\Skybox.frag", std::vector<Ruby::Attribute>{ 3 })),
			  phongShader(shaderInit(std::string(RUBY_ASSETS) + "\\shaders\\Phong.vert", std::string(RUBY_ASSETS) + "\\shaders\\Phong.frag", std::vector<Ruby::Attribute>{ 3, 3, 2 })),
			  screenQuadShader(shaderInit(std::string(RUBY_ASSETS) + "\\shaders\\ScreenQuad.vert", std::string(RUBY_ASSETS) + "\\shaders\\ScreenQuad.frag", std::vector<Ruby::Attribute>{ 3, 2 }))
		{}

		ShaderProgram shadowPhongShader;
		ShaderProgram solidShader;
		ShaderProgram directionalDepthShader;
		ShaderProgram imageShader;
		ShaderProgram skyboxShader;
		ShaderProgram phongShader;
		ShaderProgram screenQuadShader;

	private:
		ShaderProgram shaderInit(const std::string& vertexShaderPath, const std::string& fragmentShaderPath, const std::vector<Attribute>& attributes) {
			return ShaderProgram{ VertexShader{vertexShaderPath}, FragmentShader{fragmentShaderPath}, attributes };
		}
	};
}