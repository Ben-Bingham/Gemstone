#pragma once
#include <vector>

namespace Ruby {
	template<typename T>
	class Bank {
	public:
		Bank() = default;

		template<typename ...Types>
		[[nodiscard]] T* createAndGet(Types&& ...args) {
			m_Data.push_back(std::make_unique<T>(std::forward<Types>(args)...));
			return m_Data.back().get();
		}

	private:
		std::vector<std::unique_ptr<T>> m_Data{ };
	};

	using ImageBank = Bank<Image>;
	using TextureBank = Bank<Texture>;
}