#include "pch.h"
#include "Application.h"

namespace Gem {
	void Application::Load(const Celestite::Ptr<Level>& level) const {
		level->InternalLoad();

		while (window.IsOpen() && level->IsRunning()) {
			m_Engine.ExecuteFrame(level);
		}

		level->InternalUnload();
	}
}