#pragma once
#include <memory>

#include "Shaders/ShaderProgram.h"
#include "Shaders/Uniforms/UniformSet.h"

namespace Ruby {
	class Material { // TODO this is just an example and not a good base class
	public:
		Material(std::shared_ptr<Ruby::ShaderProgram> program)
			: m_UniformSet(Uniform{ "u_Roughness", roughness }, Uniform{ "u_Colour", colour }), m_Program(program) {

		}

		float roughness{ 0.0f };
		Malachite::Vector3f colour{ 1.0f, 0.0f, 0.0f };

		void use() {
			m_Program->use();
			m_UniformSet.upload();
		}

	private:
		UniformSet<float, Malachite::Vector3f> m_UniformSet;
		std::shared_ptr<Ruby::ShaderProgram> m_Program; //TODO can be made into a regular pointer
	};

}