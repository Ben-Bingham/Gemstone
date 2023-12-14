#include "Core/Settings.h"
#include "Core/Engine.h"

namespace Gem {
	Settings::Settings(Engine& engine)
		: m_Engine(engine) {

		SetVSync(false);
	}

	int Settings::GetMaxFramerate() const {
		return m_MaxFps;
	}

	void Settings::SetMaxFramerate(const int framerate) {
		m_MaxFps = framerate;
	}

	bool Settings::GetVSync() const {
		return m_VSync;
	}

	void Settings::SetVSync(const bool vSync) {
		m_VSync = vSync;
		if (m_VSync) {
			m_Engine.window.SwapInterval(1);
		}
		else {
			m_Engine.window.SwapInterval(0);
		}
	}
}