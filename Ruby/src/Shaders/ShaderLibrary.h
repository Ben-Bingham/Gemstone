#pragma once

#include "ShaderProgram.h"
#include "VertexShader.h"

namespace Ruby {
	class ShaderLibrary {
	public:
		static ShaderLibrary& get();

		ShaderLibrary(const ShaderLibrary& other) = delete;
		ShaderLibrary& operator=(const ShaderLibrary& other) = delete;

		ShaderProgram shadowPhongShader;
		ShaderProgram solidShader;
		ShaderProgram directionalDepthShader;
		ShaderProgram imageShader;
		ShaderProgram skyBoxShader;
		ShaderProgram phongShader;
		ShaderProgram screenQuadShader;

	private:
		ShaderLibrary()
			: shadowPhongShader(
				shaderInit(
					std::string(RUBY_ASSETS) + "\\shaders\\ShadowPhong.vert",
					std::string(RUBY_ASSETS) + "\\shaders\\ShadowPhong.frag"
				)
			)
			, solidShader(
				shaderInit(
					std::string(RUBY_ASSETS) + "\\shaders\\Solid.vert",
					std::string(RUBY_ASSETS) + "\\shaders\\Solid.frag"
				)
			)
			, directionalDepthShader(
				shaderInit(
					std::string(RUBY_ASSETS) + "\\shaders\\DirectionalDepth.vert",
					std::string(RUBY_ASSETS) + "\\shaders\\DirectionalDepth.frag"
				)
			)
			, imageShader(
				shaderInit(
					std::string(RUBY_ASSETS) + "\\shaders\\Image.vert",
					std::string(RUBY_ASSETS) + "\\shaders\\Image.frag"
				)
			)
			, skyBoxShader(
				shaderInit(
					std::string(RUBY_ASSETS) + "\\shaders\\Skybox.vert",
					std::string(RUBY_ASSETS) + "\\shaders\\Skybox.frag"
				)
			)
			, phongShader(
				shaderInit(
					std::string(RUBY_ASSETS) + "\\shaders\\Phong.vert",
					std::string(RUBY_ASSETS) + "\\shaders\\Phong.frag"
				)
			)
			, screenQuadShader(
				shaderInit(
					std::string(RUBY_ASSETS) + "\\shaders\\ScreenQuad.vert",
					std::string(RUBY_ASSETS) + "\\shaders\\ScreenQuad.frag"
				)
			) {
		}

		static ShaderProgram shaderInit(const std::string& vertexShaderPath, const std::string& fragmentShaderPath) {
			return ShaderProgram{VertexShader{vertexShaderPath}, FragmentShader{fragmentShaderPath}};
		}
	};
}