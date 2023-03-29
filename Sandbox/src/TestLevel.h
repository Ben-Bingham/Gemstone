#pragma once
#include "Esperite/Level.h"
#include "Apatite/Application.h"

class TestLevel : public Gem::Level {
public:
	TestLevel(Gem::Application& app);

	void Load() override;
};