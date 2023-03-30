#include "pch.h"
#include "Application.h"
#include "Level.h"

namespace Gem {
	void Application::Load(const Ptr<Level>& level) const {
		level->InternalLoad();

		while (window.IsOpen() && level->IsRunning()) {
			m_Engine.ExecuteFrame(level);
		}

		level->InternalUnload();
	}
}