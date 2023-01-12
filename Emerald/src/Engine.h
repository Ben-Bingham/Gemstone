#pragma once
#include "UglyGameObject.h"
#include "Window.h"

#include "Renderers/Renderer.h"

namespace Emerald {
	class Engine {
	public:
		Engine();

		void init(); // TODO maybe move into constructor?
		void start();

		// UglyGameObject Utility
		void enlist(const Celestite::Ptr<Esperite::UglyGameObject>& gameObject);
		
		Wavellite::Window& window() { return m_Window; } // TODO maybe replace with some kind of IO interface of something
		Ruby::Renderer& renderer() { return m_Renderer; } // TODO this is probably not needed

	private:
		Wavellite::Window m_Window;
		Ruby::Renderer m_Renderer;
		// Pyrite::Physician m_Physician;

		std::vector<Celestite::Ptr<Esperite::UglyGameObject>> m_GameObjects;
	};
}