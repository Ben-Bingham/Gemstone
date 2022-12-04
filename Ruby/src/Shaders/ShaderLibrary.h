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
					std::string(RUBY_ASSETS) + "\\shaders\\ShadowPhong.frag",
					VertexShader::LayoutData{
						VertexShader::LayoutDataElement{ VertexShader::LayoutDataElement::DataType::VECTOR_3F, VertexShader::LayoutDataElement::DataName::POSITION },
						VertexShader::LayoutDataElement{ VertexShader::LayoutDataElement::DataType::VECTOR_3F, VertexShader::LayoutDataElement::DataName::NORMAL },
						VertexShader::LayoutDataElement{ VertexShader::LayoutDataElement::DataType::VECTOR_2F, VertexShader::LayoutDataElement::DataName::TEXTURE_COORDINATES }
					}
				)
			)
			, solidShader(
				shaderInit(
					std::string(RUBY_ASSETS) + "\\shaders\\Solid.vert",
					std::string(RUBY_ASSETS) + "\\shaders\\Solid.frag",
					VertexShader::LayoutData{
						VertexShader::LayoutDataElement{ VertexShader::LayoutDataElement::DataType::VECTOR_3F, VertexShader::LayoutDataElement::DataName::POSITION },
					}
				)
			)
			, directionalDepthShader(
				shaderInit(
					std::string(RUBY_ASSETS) + "\\shaders\\DirectionalDepth.vert",
					std::string(RUBY_ASSETS) + "\\shaders\\DirectionalDepth.frag",
					VertexShader::LayoutData{
						VertexShader::LayoutDataElement{ VertexShader::LayoutDataElement::DataType::VECTOR_3F, VertexShader::LayoutDataElement::DataName::POSITION },
						VertexShader::LayoutDataElement{ VertexShader::LayoutDataElement::DataType::VECTOR_3F, VertexShader::LayoutDataElement::DataName::NORMAL },
						VertexShader::LayoutDataElement{ VertexShader::LayoutDataElement::DataType::VECTOR_2F, VertexShader::LayoutDataElement::DataName::TEXTURE_COORDINATES }
					}
				)
			)
			, imageShader(
				shaderInit(
					std::string(RUBY_ASSETS) + "\\shaders\\Image.vert",
					std::string(RUBY_ASSETS) + "\\shaders\\Image.frag",
					VertexShader::LayoutData{
						VertexShader::LayoutDataElement{ VertexShader::LayoutDataElement::DataType::VECTOR_3F, VertexShader::LayoutDataElement::DataName::POSITION },
						VertexShader::LayoutDataElement{ VertexShader::LayoutDataElement::DataType::VECTOR_2F, VertexShader::LayoutDataElement::DataName::TEXTURE_COORDINATES }
					}
				)
			)
			, skyBoxShader(
				shaderInit(
					std::string(RUBY_ASSETS) + "\\shaders\\Skybox.vert",
					std::string(RUBY_ASSETS) + "\\shaders\\Skybox.frag",
					VertexShader::LayoutData{
						VertexShader::LayoutDataElement{ VertexShader::LayoutDataElement::DataType::VECTOR_3F, VertexShader::LayoutDataElement::DataName::POSITION }
					}
				)
			)
			, phongShader(
				shaderInit(
					std::string(RUBY_ASSETS) + "\\shaders\\Phong.vert",
					std::string(RUBY_ASSETS) + "\\shaders\\Phong.frag",
					VertexShader::LayoutData{
						VertexShader::LayoutDataElement{ VertexShader::LayoutDataElement::DataType::VECTOR_3F, VertexShader::LayoutDataElement::DataName::POSITION },
						VertexShader::LayoutDataElement{ VertexShader::LayoutDataElement::DataType::VECTOR_3F, VertexShader::LayoutDataElement::DataName::NORMAL },
						VertexShader::LayoutDataElement{ VertexShader::LayoutDataElement::DataType::VECTOR_2F, VertexShader::LayoutDataElement::DataName::TEXTURE_COORDINATES }
					}
				)
			)
			, screenQuadShader(
				shaderInit(
					std::string(RUBY_ASSETS) + "\\shaders\\ScreenQuad.vert",
					std::string(RUBY_ASSETS) + "\\shaders\\ScreenQuad.frag",
					VertexShader::LayoutData{
						VertexShader::LayoutDataElement{ VertexShader::LayoutDataElement::DataType::VECTOR_3F, VertexShader::LayoutDataElement::DataName::POSITION },
						VertexShader::LayoutDataElement{ VertexShader::LayoutDataElement::DataType::VECTOR_2F, VertexShader::LayoutDataElement::DataName::TEXTURE_COORDINATES }
					}
				)
			) {
		}

		static ShaderProgram shaderInit(const std::string& vertexShaderPath, const std::string& fragmentShaderPath, const VertexShader::LayoutData layoutData) {
			return ShaderProgram{VertexShader{vertexShaderPath, layoutData}, FragmentShader{fragmentShaderPath}};
		}
	};
}