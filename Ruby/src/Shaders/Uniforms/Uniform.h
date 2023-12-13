#pragma once

#include <string>

#include "Shaders/ShaderProgram.h"

namespace Ruby {
	template<typename T>
	class Uniform {
	public:
		Uniform(std::string name, T& value)
			: m_Value(value), m_Name(std::move(name)) {

		}

		void upload() {
			ShaderProgramUploads::upload(m_Name, m_Value);
		}

	private:
		T& m_Value;
		std::string m_Name;
	};
}