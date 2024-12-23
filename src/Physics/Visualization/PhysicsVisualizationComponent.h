#pragma once

namespace Gem {
	struct PhysicsVisualizationComponent {
		bool velocity{ true };
		bool acceleration{ true };
		bool netForce{ true };
	};
}