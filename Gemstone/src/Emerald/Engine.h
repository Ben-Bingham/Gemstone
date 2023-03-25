#pragma once
#include "Esperite/GameObject.h"
#include "Wavellite/Window.h"

#include "Ruby/Renderers/RenderingSystem.h"
#include "Esperite/Scene.h"

#include "Celestite/Pointer.h"

#include "Esperite/System.h"

namespace Emerald {
	class Engine {
	public:
		Engine();

		void Start();

		void Frame();

		Engine& AddDefaultSystems();
		Engine& AddSystem(Celestite::Ptr<Esperite::System> system);

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
	};
}