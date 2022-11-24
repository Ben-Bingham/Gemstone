#pragma once
#include <memory>
#include <string>
#include <vector>

#include "Matrix.h"
#include "Vector.h"
#include "Log.h"

namespace Ruby {
	class UniformDataElement {
	public:
		explicit UniformDataElement(std::string name);

		virtual void upload() const {

		}
		std::string getName();

	protected:
		std::string m_Name;
	};

	class UniformSet {
	public:
		using UniformDataElementPtr = std::unique_ptr<UniformDataElement>;

		UniformSet(std::initializer_list<UniformDataElement> uniforms) {
			for (auto uniform : uniforms) {
				m_DataElements.push_back(std::make_unique<UniformDataElement>(uniform));
			}
		}

		template<typename T>
		T* get(const std::string& name) {
#ifdef RUBY_DEBUG
			if (!contains(name)) {
				LOG("Uniform \"" + name + "\" cant be retrieved because it dosent exist.", Lazuli::LogLevel::ERROR);
				return nullptr;
			}
#endif // RUBY_DEBUG

			for (auto& uniform : m_DataElements) {
				if (uniform->getName() == name) {
					return static_cast<T*>(uniform.get());
				}
			}
		}

		//void add(const UniformDataElementPtr& uniform);
		[[nodiscard]] bool contains(const std::string& name) const;

	private:
		std::vector<UniformDataElementPtr> m_DataElements;
	};

	enum class UniformType {
		UNKNOWN,

		FLOAT,
		INT,

		VECTOR_3F,
		VECTOR_4F,

		MATRIX_4X4F
	};

	namespace Uniform {
		template<typename T>
		class Uniform final : public UniformDataElement {
		public:
			Uniform(std::string name, T& value)
				: UniformDataElement(std::move(name)), m_Value(value) {
				
			}

			void setData(const T& value) {
				m_Value = value;
			}

			void setData(T& value) {
				m_Value = value;
			}

			void upload() const override {
				ShaderProgram::upload(m_Name, m_Value);
			}

		protected:
			T& m_Value;
		};

		using Float = Uniform<float>;
		using Int = Uniform<int>;
		using Vector3f = Uniform<Malachite::Vector3f>;
		using Vector4f = Uniform<Malachite::Vector4f>;
		using Matrix4x4f = Uniform<Malachite::Matrix4f>;
	}
}