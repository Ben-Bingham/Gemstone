#include "pch.h"
#include "Application.h"

namespace Gem {
	Application::Application(Engine& engine)
		: m_Engine(engine) {

	}

	void Application::Load(const Celestite::Ptr<Level>& scene) const {
		while (window.IsOpen() && scene->IsRunning()) {
			m_Engine.ExecuteFrame(scene);
		}
	}
}