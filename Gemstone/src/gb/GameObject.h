#pragma once

#include "Esperite/GameObject.h"

#include "Esperite/ECSScene.h"

namespace Gem {
	class GameObject {
	public:
		GameObject();

		template<typename T/*, typename...Types*/> //TODO uncomment
		void AddComponent(/*Types...args*/) {
			m_Owner->AddComponent<T>(m_Handle);
		}

		template<typename T>
		[[nodiscard]] T* GetComponent() const {
			return m_Owner->GetComponent<T>(m_Handle);
		}

		static inline Esperite::ECSScene* activeScene{ nullptr };

	private:
		Esperite::ECSScene* m_Owner;
		Esperite::InternalGameObject m_Handle;
	};
}