#include "pch.h"
#include "System.h"
namespace Esperite {
	System::System() {
		// m_Owner.AddSystem(this); //TODO was working on last
	}

	void System::StartUp(ECSScene* scene) {}
	void System::PreStep(ECSScene* scene) {}
	void System::Step(ECSScene* scene) {}
	void System::EndStep(ECSScene* scene) {}
	void System::ShutDown(ECSScene* scene) {}
}