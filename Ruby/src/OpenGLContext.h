#pragma once

namespace Ruby {
	struct OpenGlContext {
		bool depthMask{ true };

		enum class FaceCull {
			NONE,
			BACK,
			FRONT
		};
		FaceCull faceToCull{ FaceCull::BACK };

		enum class DepthFunction {
			NONE,
			LESS_THAN,
			EQUAL,
			LESS_THAN_OR_EQUAL,
			GREATER_THAN,
			GREATER_THAN_OR_EQUAL
		};
		DepthFunction depthFunction{ DepthFunction::LESS_THAN };

		enum class FrontFace {
			CLOCKWISE,
			COUNTER_CLOCKWISE
		};
		FrontFace frontFace{ FrontFace::CLOCKWISE };

		void makeCurrent(bool force = false) const;
		void forceMakeCurrent() const;

		static OpenGlContext getCurrent();

	private:
		inline static const OpenGlContext* m_Context{ nullptr };
	};
}