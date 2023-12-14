#pragma once

namespace Gem {
	class Engine;

	class Settings {
	public:
		Settings(Engine& engine);

		[[nodiscard]] int GetMaxFramerate() const;
		void SetMaxFramerate(int framerate); // TODO need some way of making unlimited

		[[nodiscard]] bool GetVSync() const;
		void SetVSync(bool vSync);  // VSync always takes priority over FPS.

	private:
		unsigned int m_MaxFps{ 60 };
		bool m_VSync{ false };

		Engine& m_Engine;
	};
}