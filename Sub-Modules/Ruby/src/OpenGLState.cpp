#include "OpenGLState.h"

#include <GL/glew.h>

namespace Ruby {
	OpenGlState& OpenGlState::get() {
		static OpenGlState instance;
		return instance;
	}

	void OpenGlState::setDepthTesting(const bool depthTesting) {
		if (m_DepthTesting == depthTesting && m_DepthTesting != NoneBool::NONE) {
			return;
		}

		if (depthTesting) {
			m_DepthTesting = NoneBool::TRUE;
		}
		else {
			m_DepthTesting = NoneBool::FALSE;
		}

		switch (m_DepthTesting) {
		case NoneBool::NONE: 
			break;
		case NoneBool::TRUE:
			glEnable(GL_DEPTH_TEST);
			break;
		case NoneBool::FALSE:
			glDisable(GL_DEPTH_TEST);
			break;
		}
	}

	bool OpenGlState::getDepthTesting() const {
		if (m_DepthTesting == true) {
			return true;
		}
		return false;
	}

	void OpenGlState::setDepthBufferWriting(const bool depthBufferWriting) {
		if (m_DepthBufferWriting == depthBufferWriting && m_DepthBufferWriting != NoneBool::NONE) {
			return;
		}

		if (depthBufferWriting) {
			m_DepthBufferWriting = NoneBool::TRUE;
		}
		else {
			m_DepthBufferWriting = NoneBool::FALSE;
		}

		if (m_DepthBufferWriting == true) {
			glDepthMask(GL_TRUE);
		}
		else {
			glDepthMask(GL_FALSE);
		}
	}

	bool OpenGlState::getDepthBufferWriting() const {
		if (m_DepthBufferWriting == true) {
			return true;
		}
		return false;
	}

	void OpenGlState::setFaceToCull(const Face face) {
		if (m_CulledFace == face && m_CulledFace != Face::NONE) {
			return;
		}

		switch (face) {
		case Face::FRONT:
			if (m_CulledFace == Face::NONE) {
				glEnable(GL_CULL_FACE);
			}
			glCullFace(GL_FRONT);
			break;
		case Face::BACK:
			if (m_CulledFace == Face::NONE) {
				glEnable(GL_CULL_FACE);
			}
			glCullFace(GL_BACK);
			break;
		case Face::NONE:
			glDisable(GL_CULL_FACE);
			break;
		}
		m_CulledFace = face;
	}

	OpenGlState::Face OpenGlState::getFaceToCull() const {
		return m_CulledFace;
	}

	void OpenGlState::setDepthFunction(const Comparison comparison) {
		if (m_DepthFunction == comparison && comparison != Comparison::NEVER) {
			return;
		}

		m_DepthFunction = comparison;
		switch (m_DepthFunction) {
		case Comparison::NEVER:
			glDisable(GL_NEVER);
			break;
		case Comparison::LESS_THAN:
			glDepthFunc(GL_LESS);
			break;
		case Comparison::EQUAL:
			glDepthFunc(GL_EQUAL);
			break;
		case Comparison::LESS_THAN_OR_EQUAL:
			glDepthFunc(GL_LEQUAL);
			break;
		case Comparison::GREATER_THAN:
			glDepthFunc(GL_GREATER);
			break;
		case Comparison::GREATER_THAN_OR_EQUAL:
			glDepthFunc(GL_GEQUAL);
			break;
		}
	}

	OpenGlState::Comparison OpenGlState::getDepthFunction() const {
		return m_DepthFunction;
	}

	void OpenGlState::setFrontFaceDirection(const Direction direction) {
		if (m_FrontFaceDirection == direction && m_FrontFaceDirection != Direction::NONE) {
			return;
		}

		m_FrontFaceDirection = direction;

		switch (m_FrontFaceDirection) {
		case Direction::NONE:
			break;
		case Direction::CLOCKWISE:
			glFrontFace(GL_CW);
			break;
		case Direction::COUNTER_CLOCKWISE:
			glFrontFace(GL_CCW);
			break;
		}
	}

	OpenGlState::Direction OpenGlState::getFrontFaceDirection() const {
		return m_FrontFaceDirection;
	}
}