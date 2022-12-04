#pragma once
#include <memory>

namespace Ruby {
	template<typename T>
	using Ptr = std::shared_ptr<T>;

	template<typename T, typename ... Args>
	constexpr Ptr<T> createPtr(Args&& ... args) {
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using UPtr = std::unique_ptr<T>;

	template<typename T, typename ... Args>
	constexpr UPtr<T> createUPtr(Args&& ... args) {
		return std::make_unique<T>(std::forward<Args>(args)...);
	}
}