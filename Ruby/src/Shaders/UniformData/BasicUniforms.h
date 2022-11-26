#pragma once

#include "UniformDataElement.h"
#include "Vector.h"
#include "Matrix.h"

namespace Ruby {
	namespace Uniform {
		template<typename T>
		class Uniform final : public UniformDataElement {
		public:
			Uniform(std::string name, T& value)
				: UniformDataElement(std::move(name)), m_Value(value) {

			}

			void setData(T& value) {
				m_Value = value;
			}

			T& getValue() {
				return m_Value;
			}

			void upload() const override {
				// ShaderProgram::upload(m_Name, m_Value);
			}

		protected:
			T& m_Value; //TODO can maybe be const
		};

		using Float = Uniform<float>;
		using Int = Uniform<int>;
		using Vector3f = Uniform<Malachite::Vector3f>;
		using Vector4f = Uniform<Malachite::Vector4f>;
		using Matrix4x4f = Uniform<Malachite::Matrix4f>;
	}
}