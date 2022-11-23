#pragma once
#include <memory>

#include "Shaders/ShaderProgram.h"

namespace Ruby {
	class Material {
	public:
		using ShaderProgramPtr = std::shared_ptr<ShaderProgram>;
		Material(ShaderProgramPtr shader);
		Material();

		Material(const Material& other) = default;
		Material(Material&& other) noexcept = default;
		Material& operator=(const Material& other) = default;
		Material& operator=(Material&& other) noexcept = default;
		virtual ~Material() = default;

	private:
		ShaderProgramPtr m_Shader;
	};
}