#pragma once
#include <memory>
#include <string>
#include <vector>
#include <unordered_map>

#include "UniformDataElement.h"

#include "Matrix.h"
#include "Vector.h"
#include "Log.h"

namespace Ruby {
	class UniformSet {
	public:
		using UniformDataElementPtr = std::unique_ptr<UniformDataElement>;

		UniformSet(std::initializer_list<UniformDataElement> uniforms);

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

		[[nodiscard]] bool contains(const std::string& name) const;

	private:
		//std::unordered_map<std::string, UniformDataElementPtr> m_Uniforms;
		std::vector<UniformDataElementPtr> m_DataElements;
	};
}