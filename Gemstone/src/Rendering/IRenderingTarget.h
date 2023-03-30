#pragma once

namespace Gem {
	class IRenderingTarget {
	public:
		IRenderingTarget() = default;
		virtual ~IRenderingTarget() = default;

		virtual void Target() {}
	};
}