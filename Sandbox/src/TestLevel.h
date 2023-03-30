#pragma once
#include "Core/Game Flow/Level.h"

class TestLevel : public Gem::Level {
public:
	TestLevel(Gem::Application& app);

	void Load() override;
};