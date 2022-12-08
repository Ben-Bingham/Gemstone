#pragma once

namespace Ruby {
	class OpenGlState {
	public:
		static OpenGlState& get();

		OpenGlState(const OpenGlState& other) = delete;
		OpenGlState& operator=(const OpenGlState& other) = delete;

		enum class NoneBool {
			NONE,
			TRUE,
			FALSE
		};

		friend bool operator==(const bool& lhs, const NoneBool& rhs) {
			if (rhs == NoneBool::TRUE && lhs) {
				return true;
			}
			return false;
		}

		friend bool operator==(const NoneBool& lhs, const bool& rhs) {
			return operator==(rhs, lhs);
		}

		void setDepthTesting(bool depthTesting);
		[[nodiscard]] bool getDepthTesting() const;

		void setDepthBufferWriting(bool depthBufferWriting);
		[[nodiscard]] bool getDepthBufferWriting() const;

		enum class Face {
			FRONT,
			BACK,
			NONE
		};
		void setFaceToCull(Face face);
		[[nodiscard]] Face getFaceToCull() const;

		enum class Comparison {
			NEVER,
			LESS_THAN,
			EQUAL,
			LESS_THAN_OR_EQUAL,
			GREATER_THAN,
			GREATER_THAN_OR_EQUAL
		};
		void setDepthFunction(Comparison comparison);
		[[nodiscard]] Comparison getDepthFunction() const;

		enum class Direction {
			NONE,
			CLOCKWISE,
			COUNTER_CLOCKWISE
		};
		void setFrontFaceDirection(Direction direction);
		[[nodiscard]] Direction getFrontFaceDirection() const;

	private:
		OpenGlState() = default;

		NoneBool m_DepthBufferWriting{ NoneBool::NONE };
		NoneBool m_DepthTesting{ NoneBool::NONE };
		Face m_CulledFace{ Face::NONE };
		Comparison m_DepthFunction{ Comparison::NEVER };
		Direction m_FrontFaceDirection{ Direction::NONE };
	};
}