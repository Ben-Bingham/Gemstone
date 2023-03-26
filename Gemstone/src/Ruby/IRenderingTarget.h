#pragma once

namespace Ruby {
	class IRenderingTarget {
	public:
		IRenderingTarget() = default;
		virtual ~IRenderingTarget() = default;

		virtual void Target() {}
	};
}