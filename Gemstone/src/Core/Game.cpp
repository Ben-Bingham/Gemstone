#include "pch.h"
#include "Game.h"

namespace Gem {
	Game::Game(Engine_New& engine)
		: levelManager(engine), gameLoop(engine), engine(engine) {
		
	}

	void Game::Run(Ptr<Level_New> level, ConditionFunction conditionFunction) {
		//ecs.LoadLevel(level);

		//double dt = 1 / settings.fps; // TODO also incorperate vsync toggle
		double dt = 1.0f / 16.0f;
		while (conditionFunction(level) == true) {
			const double frameStartTime = engine.glfwContext.time.GetElapsedTime();

			engine.glfwContext.PollEvents();
			engine.eventSystem.Distribute();

			//ecs.Step(dt);

			LOG(std::to_string(dt));

			window.SwapBuffers();

			dt = DelayFrame(frameStartTime);
		}
	}

	double Game::DelayFrame(double frameStartTime) {
		// TODO need a condition about weather or not we are running in vsync or not
		//double dt = 1 / settings.fps; // TODO
		double dt = 1.0f / 16.0f;

		const double waitTime = std::ceil((engine.glfwContext.time.GetElapsedTime() - frameStartTime) / dt) * dt;

		engine.glfwContext.time.Wait(waitTime);
		return engine.glfwContext.time.GetElapsedTime() - frameStartTime;
	}
}