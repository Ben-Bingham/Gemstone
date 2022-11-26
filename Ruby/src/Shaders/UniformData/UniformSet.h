#pragma once
#include <any>
#include <memory>
#include <string>
#include <vector>
#include <unordered_map>

#include "UniformDataElement.h"
#include "BasicUniforms.h"

#include "Matrix.h"
#include "Vector.h"
#include "Log.h"

namespace Ruby {
	class UniformSetBase {
	public:
		UniformSetBase() = default;
		virtual ~UniformSetBase() = 0;

		virtual void upload() = 0;
	};

	template<size_t N>
	struct StringLiteral {
		constexpr StringLiteral(const char(&str)[N]) {
			std::copy_n(str, N, value);
		}

		char value[N];
	};

	//template<const char* Str>
	//struct String {
	//	constexpr String(Str)
	//};

	template<typename T1, const char* Name1>
	class UniformSet : public UniformSetBase {
	public:
		UniformSet(T1 value1)
			: uniform1(Name1, value1) { }

		void upload() override {
			uniform1.upload();
		}

		Uniform::Uniform<T1> uniform1;
	};

	//template<
	//	typename T1, const char* Name1, 
	//	typename T2, const char* Name2
	//>
	//class UniformSet : public UniformSetBase {
	//public:
	//	UniformSet(T1 value1, T2 value2)
	//		: uniform1(Name1, value1), uniform2(Name2, value2) {
	//	}

	//	void upload() override {
	//		uniform1.upload();
	//	}

	//	Uniform::Uniform<T1> uniform1;
	//	Uniform::Uniform<T2> uniform2;
	//};


	//template<typename ...T>
	//class UniformSet {
	//	template<int N>
	//	using NthType = std::tuple_element_t<N, std::tuple<T...>>;

	//public:
	//	UniformSet(const std::initializer_list<const char*> names, T...) 
	//		: m_Uniforms(std::tuple<Uniform::Uniform<T>...>("hello")) {

	//		/*assert(names.size() == m_NumberOfUniforms);

	//		std::vector<std::string> uniformNames;
	//		uniformNames.resize(names.size());
	//		for (auto& name : names) {
	//			uniformNames.emplace_back(name);
	//		}

	//		std::get<0>(m_Uniforms);*/
	//		int i = 0;
	//		std::initializer_list<const char*>::iterator it = names.begin();
	//		std::apply([&](auto&... args) {
	//			args.setName(*it);
	//			it++;
	//		}, m_Uniforms);

	//	}

// 		template<typename Type>
// 		void set(const std::string& name, Type& value) {
// #ifdef RUBY_DEBUG
// 			if (m_UniformMap.find(name) == m_UniformMap.end()) {
// 				LOG("Attempted to set the Uniform: \"" + name + "\" but it does not exist.", Lazuli::LogLevel::ERROR);
// 				return;
// 			}
// #endif // RUBY_DEBUG
//
// 			m_UniformMap[name] = value;
// 		}

//		decltype(auto) get(const std::string& name) {
//#ifdef RUBY_DEBUG
//			if (m_UniformMap.find(name) == m_UniformMap.end()) {
//				LOG("Attempted to get the Uniform: \"" + name + "\" but it does not exist.", Lazuli::LogLevel::ERROR);
//			}
//#endif // RUBY_DEBUG
//
//			return std::get<0>(m_Uniforms);
//		}

	//private:
	//	//std::unordered_map<std::string, std::any> m_UniformMap;
	//	std::tuple<Uniform::Uniform<T>...> m_Uniforms;
	//	const size_t m_NumberOfUniforms = sizeof...(T);
	//};


// 	class UniformSet {
// 	public:
// 		using UniformDataElementPtr = std::unique_ptr<UniformDataElement>;
//
// 		UniformSet(std::initializer_list<UniformDataElement> uniforms);
//
// 		template<typename T>
// 		T* get(const std::string& name) {
// #ifdef RUBY_DEBUG
// 			if (!contains(name)) {
// 				LOG("Uniform \"" + name + "\" cant be retrieved because it dosent exist.", Lazuli::LogLevel::ERROR);
// 				return nullptr;
// 			}
// #endif // RUBY_DEBUG
//
// 			for (auto& uniform : m_DataElements) {
// 				if (uniform->getName() == name) {
// 					return static_cast<T*>(uniform.get());
// 				}
// 			}
// 		}
//
// 		[[nodiscard]] bool contains(const std::string& name) const;
//
// 	private:
// 		//std::unordered_map<std::string, UniformDataElementPtr> m_Uniforms;
// 		std::vector<UniformDataElementPtr> m_DataElements;
// 	};
}