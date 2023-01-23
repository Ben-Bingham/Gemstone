#pragma once
#include "GameObject.h"
#include "Window.h"

#include "Renderers/Renderer.h"
#include "Scene.h"
#include "System.h"
#include "Timing.h"

namespace Emerald {
	class Engine {
	public:
		Engine();

		void init(); // TODO maybe move into constructor?
		void start();
		
		// Wavellite::Window& window() { return m_Window; } // TODO maybe replace with some kind of IO interface of something
		// Ruby::Renderer& renderer() { return m_Renderer; } // TODO this is probably not needed
		// float DeltaTime() const;

		Esperite::Scene* activeScene{ nullptr };

	private:
		std::vector<Celestite::Ptr<Esperite::System>> m_Systems; //TODO can maybe be UPtr

		Wavellite::Window m_Window; //TODO at some point make this a member of the camera, could even implement a render output interface that the camera outputs to or smth
		// Wavellite::Time m_Time;
		// float m_DeltaTime;

		// Ruby::Renderer m_Renderer;
		// Pyrite::Physician m_Physician;

		std::vector<Celestite::Ptr<Esperite::GameObject>> m_GameObjects;
	};
}