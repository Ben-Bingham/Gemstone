#pragma once
#include "Window.h"

#include "ECS/GameObject.h"

#include "Renderers/Renderer.h"

namespace Emerald {
	class Engine {
	public:
		Engine();

		void init(); // TODO maybe move into constructor?
		void start();

		// GameObject Utility
		void enlist(const Celestite::Ptr<GameObject>& gameObject);

	private:
		Wavellite::Window m_Window;
		Ruby::Renderer m_Renderer;
		// Pyrite::Physician m_Physician;

		std::vector<Celestite::Ptr<GameObject>> m_GameObjects;
	};
}