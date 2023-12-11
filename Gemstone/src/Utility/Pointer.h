#pragma once
#include <memory>
#include "Gem.h"

namespace Gem {
	template<typename T>
	using Ptr = std::shared_ptr<T>;

	template<typename T, typename ... Args>
	GEM_API constexpr Ptr<T> CreatePtr(Args&& ... args) {
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using UPtr = std::unique_ptr<T>;

	template<typename T, typename ... Args>
	GEM_API constexpr UPtr<T> CreateUPtr(Args&& ... args) {
		return std::make_unique<T>(std::forward<Args>(args)...);
	}
}