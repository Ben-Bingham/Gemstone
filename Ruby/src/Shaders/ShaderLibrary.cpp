#include "ShaderLibrary.h"

#include <ranges>

#include "VertexShader.h"
#include "FragmentShader.h"

namespace Ruby {
	ShaderLibrary& ShaderLibrary::Get() {
		static ShaderLibrary instance;

		return instance;
	}

	ShaderLibrary::ShaderLibrary()
		: shadowPhongShader(
			CreateProgram(
				std::string(RUBY_ASSETS) + "\\shaders\\ShadowPhong.vert",
				std::string(RUBY_ASSETS) + "\\shaders\\ShadowPhong.frag"
			)
		)
		, solidShader(
			CreateProgram(
				std::string(RUBY_ASSETS) + "\\shaders\\Solid.vert",
				std::string(RUBY_ASSETS) + "\\shaders\\Solid.frag"
			)
		)
		, directionalDepthShader(
			CreateProgram(
				std::string(RUBY_ASSETS) + "\\shaders\\DirectionalDepth.vert",
				std::string(RUBY_ASSETS) + "\\shaders\\DirectionalDepth.frag"
			)
		)
		, imageShader(
			CreateProgram(
				std::string(RUBY_ASSETS) + "\\shaders\\Image.vert",
				std::string(RUBY_ASSETS) + "\\shaders\\Image.frag"
			)
		)
		, skyBoxShader(
			CreateProgram(
				std::string(RUBY_ASSETS) + "\\shaders\\Skybox.vert",
				std::string(RUBY_ASSETS) + "\\shaders\\Skybox.frag"
			)
		)
		, phongShader(
			CreateProgram(
				std::string(RUBY_ASSETS) + "\\shaders\\Phong.vert",
				std::string(RUBY_ASSETS) + "\\shaders\\Phong.frag"
			)
		)
		, screenQuadShader(
			CreateProgram(
				std::string(RUBY_ASSETS) + "\\shaders\\ScreenQuad.vert",
				std::string(RUBY_ASSETS) + "\\shaders\\ScreenQuad.frag"
			)
		) {
	}

	ShaderProgram ShaderLibrary::CreateProgram(const std::string& vertexShaderPath, const std::string& fragmentShaderPath) {
		return ShaderProgram{ VertexShader{vertexShaderPath}, FragmentShader{fragmentShaderPath} };
	}

	ShaderHandle ShaderLibrary::LoadShader(const std::string& vertexPath, const std::string& fragmentPath) {
		const ShaderHandle handle = std::hash<std::string>{}(vertexPath + fragmentPath);

		for (auto& key : std::views::keys(m_Shaders)) {
			if (key == handle) {
				return handle;
			}
		}

		m_Shaders[handle] = Celestite::CreatePtr<ShaderProgram>(CreateProgram(vertexPath, fragmentPath));
		return handle;
	}
}