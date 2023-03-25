#pragma once

#include <tuple>

#include "Uniform.h"

namespace Ruby {
	namespace Util {
		template<size_t I = 0, typename... Tuple>
		void upload(std::tuple<Uniform<Tuple>...>& t) {
			std::get<I>(t).upload();
			if constexpr (I + 1 != sizeof...(Tuple)) {
				upload<I + 1>(t);
			}
		}
	}

	template<typename...T>
	class UniformSet {
	public:
		explicit UniformSet(Uniform<T>... initList)
			: m_Uniforms(initList...) {

		}

		void upload() {
			Util::upload(m_Uniforms);
		}

	private:
		std::tuple<Uniform<T>...> m_Uniforms;
		const size_t m_Size{ sizeof...(T) };
	};
}