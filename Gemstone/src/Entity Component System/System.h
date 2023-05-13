#pragma once

namespace Gem {
	class EntityManager;

	class System {
	public:
		System() = default;
		System(const System& other) = default;
		System(System&& other) noexcept = default;
		System& operator=(const System& other) = default;
		System& operator=(System&& other) noexcept = default;
		virtual ~System() = default;

		virtual void StartUp(EntityManager& entityManager);
		virtual void PreStep(EntityManager& entityManager);
		virtual void Step(EntityManager& entityManager);
		virtual void EndStep(EntityManager& entityManager);
		virtual void ShutDown(EntityManager& entityManager);
	};
}