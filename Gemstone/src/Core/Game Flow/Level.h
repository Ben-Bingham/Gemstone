#pragma once

namespace Gem {
	class Level {
	public:
		Level() = default;
		Level(const Level& other) = default;
		Level(Level&& other) noexcept = default;
		Level& operator=(const Level& other) = delete;
		Level& operator=(Level&& other) noexcept = delete;
		virtual ~Level() = default;

		virtual void Load();
		void Step(float dt);
		virtual void Unload();

		[[nodiscard]] bool IsRunning() const;
		void Stop();

		void InternalLoad();
		void InternalUnload();

	private:
		bool m_Running{ false };

	protected:
		/*EntityComponentSystem m_Ecs{ };
		EntityManager& m_EntityManager{ m_Ecs.entityManager };*/
	};
}