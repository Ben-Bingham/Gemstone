#pragma once
#include <memory>
#include <string>
#include <vector>

#include "Matrix.h"
#include "Vector.h"

namespace Ruby {
	class UniformDataElement {
	public:
		explicit UniformDataElement(std::string name);
		UniformDataElement(const UniformDataElement& other) = default;
		UniformDataElement(UniformDataElement&& other) noexcept = default;
		UniformDataElement& operator=(const UniformDataElement& other) = default;
		UniformDataElement& operator=(UniformDataElement&& other) noexcept = default;
		virtual ~UniformDataElement() = default;

		virtual void upload() const = 0;
		std::string getName();

	protected:
		std::string m_Name;
	};

	class UniformSet {
	public:
		using UniformDataElementPtr = std::unique_ptr<UniformDataElement>;

		UniformSet() = default;

		void add(const UniformDataElementPtr& uniform);
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
			Uniform(std::string name, const T& value = T{})
				: UniformDataElement(std::move(name)), m_Value(value) {
				
			}

			void setData(const T& value) {
				m_Value = value;
			}

			void upload() const override {
				ShaderProgram::upload(m_Name, m_Value);
			}

		protected:
			const T& m_Value;
		};

		using Float = Uniform<float>;
		using Int = Uniform<int>;
		using Vector3f = Uniform<Malachite::Vector3f>;
		using Vector4f = Uniform<Malachite::Vector4f>;
		using Matrix4x4f = Uniform<Malachite::Matrix4f>;
	}
}