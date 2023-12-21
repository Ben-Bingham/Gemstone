#pragma once

namespace Gem {
	class Settings {
		friend class Engine;

		static void StartUp();
		static void ShutDown();

		Settings() = default;
		~Settings() = default;

		static inline bool m_Started{ false };

	public:
		static Settings& Get();

		Settings(const Settings& other) = delete;
		Settings(Settings&& other) noexcept = default;
		Settings& operator=(const Settings& other) = delete;
		Settings& operator=(Settings&& other) noexcept = default;

		[[nodiscard]] int GetMaxFramerate() const;
		void SetMaxFramerate(int framerate); // TODO need some way of making unlimited

		[[nodiscard]] bool GetVSync() const;
		void SetVSync(bool vSync);  // VSync always takes priority over FPS.

	private:
		unsigned int m_MaxFps{ 60 };
		bool m_VSync{ false };
	};
}