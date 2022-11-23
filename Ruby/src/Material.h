#pragma once
#include <memory>

#include "Shaders/ShaderProgram.h"

namespace Ruby {
	class Material {
	public:
		using ShaderProgramPtr = std::shared_ptr<ShaderProgram>;
		Material(ShaderProgramPtr shader);

		Material(const Material& other) = default;
		Material(Material&& other) noexcept = default;
		Material& operator=(const Material& other) = default;
		Material& operator=(Material&& other) noexcept = default;
		virtual ~Material() = default;

		struct ShaderInputData {
			enum class DataType {
				VECTOR_3F,
				VECTOR_2F,
				MATRIX_4X4F
			};
			DataType dataType;
			unsigned int location;
		};

	private:
		ShaderProgramPtr m_Shader;
		std::vector<ShaderInputData> dataLayout;
	};
}