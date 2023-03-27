#pragma once
#include "Celestite/Pointer.h"

#include "Emerald/Engine.h"

#include "Esperite/ECSScene.h"
#include "Esperite/Level.h"

#include "Wavellite/Window.h"

namespace Gem {
	class Application {
	public:
		Application(Engine& engine);

		void Load(const Celestite::Ptr<Level>& scene) const;

		Wavellite::Window window{ };

	private:
		Engine& m_Engine;
	};
}