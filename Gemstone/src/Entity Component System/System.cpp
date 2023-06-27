#include "pch.h"
#include "System.h"
#include "EntityManager.h"

namespace Gem {
	void System::StartUp() {}
	void System::PreStep(EntityManager& entityManager) {}
	void System::Step(EntityManager& entityManager, float dt) {}
	void System::EndStep(EntityManager& entityManager) {}
	void System::ShutDown() {}
}