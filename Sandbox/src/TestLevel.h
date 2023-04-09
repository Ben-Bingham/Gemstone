#pragma once
#include "Core/Event System/EventHandler.h"
#include "Core/Game Flow/Level.h"

struct StopLevel{};

void MenuUI();

class TestLevel : public Gem::Level, Gem::EventHandler<StopLevel> {
public:
	TestLevel() = default;

	void Load() override;

	void HandleEvent(const StopLevel& event) override;
};