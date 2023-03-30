#pragma once
#include "Application.h"

#include "Entity Component System//EntityComponentSystem.h"

namespace Gem {
	/*
	Stores data and instructions for running a single Level
	 */
	class Level {
	public:
		Level(Application& app);
		Level(const Level& other) = default;
		Level(Level&& other) noexcept = default;
		Level& operator=(const Level& other) = delete;
		Level& operator=(Level&& other) noexcept = delete;
		virtual ~Level() = default;

		virtual void Load();
		void Step();
		virtual void Unload();

		[[nodiscard]] bool IsRunning() const;
		void Stop();
		
		[[nodiscard]] EntityComponentSystem& ECS();

		void InternalLoad();
		void InternalUnload();

	private:
		bool m_Running{ true };

	protected:
		EntityComponentSystem m_EntityComponentSystem{ };
		Application& m_App;
	};
}