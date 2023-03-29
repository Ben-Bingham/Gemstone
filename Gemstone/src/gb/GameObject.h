#pragma once
#include "Emerald/EntityComponentSystem.h"
#include "Esperite/GameObject.h"
#include "Esperite/Scene.h"

namespace Gem {
	class GameObject {
		struct UniqueTag1{};
		struct UniqueTag2 {};
	public:
		GameObject(EntityComponentSystem& owner, const InternalGameObject handle);
		GameObject(EntityComponentSystem& owner);

		template<typename T>
		GameObject& AddComponent(T component = T{}) {
			m_Owner.scene.AddComponent(m_Handle, component);
			return *this;
		}

		template<typename T>
		[[nodiscard]] bool HasComponent() const {
			return m_Owner.scene.HasComponent<T>(m_Handle);
		}

		template<typename T>
		[[nodiscard]] T* GetComponent() {
			return m_Owner.scene.GetComponent<T>(m_Handle);
		}

		template<typename ...Ts, typename ...Args>
		static GameObject CreateGameObject(EntityComponentSystem& owner, Args...components) {
			if constexpr (sizeof...(Args) > sizeof...(Ts)) {
				// LOG("Two many components given.", Lazuli::LogLevel::TERMINAL);
				return GameObject{ owner, NULL_GAME_OBJECT }; // Two many components given
			}
			else if constexpr (sizeof...(Args) == sizeof...(Ts)) {
				return GameObject{ UniqueTag1{}, owner, components... };
			}
			else if constexpr (sizeof...(Args) == 0) {
				return GameObject{ UniqueTag1{}, owner, Ts{}... };
			}
			else {
				return GameObject{ owner, NULL_GAME_OBJECT };
				// return GameObject{ UniqueTag2{}, owner, std::tuple<Args...>{components...} }; //TODO allow for not initializing all components
			}
		}

	private:
		template<typename ...Ts>
		GameObject(UniqueTag1 tag, EntityComponentSystem& owner, Ts...components)
			: m_Owner(owner), m_Handle(m_Owner.scene.NewGameObject()) {

			(AddComponent<Ts>(components) , ...);
		}
		
		// template<typename ...Ts, typename ...Gs>
		// GameObject(UniqueTag2 tag, EntityComponentSystem& owner, std::tuple<Gs...> components)
		// 	: m_Owner(owner), m_Handle(m_Owner.scene.NewGameObject()) {
		//
		// 	int i = 0;
		// 	([&] {
		// 		AddComponent<Gs>(std::get<i>(components)); // This I does not work here, not const
		// 		i++;
		// 	}() , ...); // Still runs with the squiggles
		//
		// 	([&] {
		// 		if (!HasComponent<Ts>()) {
		// 			AddComponent<Ts>();
		// 		}
		// 	}(), ...); // Still runs with the squiggles
		// }

		EntityComponentSystem& m_Owner;
		InternalGameObject m_Handle;
	};
}