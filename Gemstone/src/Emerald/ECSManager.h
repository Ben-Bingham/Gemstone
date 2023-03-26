#pragma once
#include "Esperite/GameObject.h"
#include "Wavellite/Window.h"

#include "Ruby/Renderers/RenderingSystem.h"
#include "Esperite/Scene.h"

#include "Celestite/Pointer.h"

#include "Esperite/System.h"
#include "Esperite/Engine Systems/EngineSystem.h"

#include "Rutile/Interfaces/IRenderingAPI.h"
#include "Rutile/Interfaces/IWindowAPI.h"

namespace Emerald {
	class ECSManager {
	public:
		ECSManager();

		void Start();

		void Frame();

		ECSManager& AddDefaultSystems();
		ECSManager& AddSystem(Celestite::Ptr<Esperite::System> system);

		template<typename T>
		Celestite::Ptr<T> GetSystem() {
			for (auto& system : m_Systems) {
				auto target = std::dynamic_pointer_cast<T>(system);

				if (target != nullptr) {
					return target;
				}
			}
			return nullptr;
		}

		Esperite::Scene* activeScene{ nullptr };

	private:
		std::vector<Celestite::Ptr<Esperite::System>> m_Systems;



		float m_FrameTime{ 0.0f };
		// Celestite::UPtr<Wavellite::Window> m_Window; //TODO at some point make this a member of the camera, could even implement a render output interface that the camera outputs to or smth

		// std::vector<Celestite::Ptr<Esperite::GameObject>> m_GameObjects;









		Celestite::Ptr<Rutile::IWindowAPI> m_WindowAPI{ nullptr };
		Celestite::Ptr<Rutile::IRenderingAPI> m_RenderingAPI{ nullptr };
	};
}