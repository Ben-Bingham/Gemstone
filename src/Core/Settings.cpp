#include "Core/Settings.h"
#include "Core/Window.h"

#include "Utility/Log.h"

namespace Gem {
	void Settings::StartUp() {
		m_Started = true;

		Get().SetVSync(false);
	}

	void Settings::ShutDown() {
		m_Started = false;
	}

	Settings& Settings::Get() {
		if (!m_Started) {
			LOG("Failed to StartUp Settings, before using it.", LogLevel::TERMINAL);
		}

		static Settings settings;
		return settings;
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
			Window::Get().SwapInterval(1);
		}
		else {
			Window::Get().SwapInterval(0);
		}
	}
}