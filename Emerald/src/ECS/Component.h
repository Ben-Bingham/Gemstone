#pragma once

namespace Emerald {
	class Component {
	public:
		Component() = default;

		virtual void onUpdate() {}
	};
}