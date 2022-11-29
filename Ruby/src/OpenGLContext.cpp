#include "OpenGLContext.h"

#include <GL/glew.h>

namespace Ruby {
	void OpenGlContext::makeCurrent(bool force) const {
		if ( !force && m_Context == this) {
			return;
		}

		if (force || m_Context != nullptr && m_Context->depthMask != this->depthMask) {
			if (depthMask) {
				glDepthMask(GL_TRUE);
			}
			else {
				glDepthMask(GL_FALSE);
			}
		}

		if (force || m_Context != nullptr && m_Context->faceToCull != this->faceToCull) {
			switch (faceToCull) {
			case FaceCull::NONE:
				glDisable(GL_CULL_FACE);
				break;
			case FaceCull::BACK:
				glEnable(GL_CULL_FACE);
				glCullFace(GL_BACK);
				break;
			case FaceCull::FRONT:
				glEnable(GL_CULL_FACE);
				glCullFace(GL_FRONT);
				break;
			}
		}

		if (force || m_Context != nullptr && m_Context->depthFunction != this->depthFunction) {
			switch (depthFunction) {
			case DepthFunction::NONE:
				glDisable(GL_DEPTH_TEST);
				break;
			case DepthFunction::LESS_THAN:
				glEnable(GL_DEPTH_TEST);
				glDepthFunc(GL_LESS);
				break;
			case DepthFunction::EQUAL:
				glEnable(GL_DEPTH_TEST);
				glDepthFunc(GL_EQUAL);
				break;
			case DepthFunction::LESS_THAN_OR_EQUAL:
				glEnable(GL_DEPTH_TEST);
				glDepthFunc(GL_LEQUAL);
				break;
			case DepthFunction::GREATER_THAN:
				glEnable(GL_DEPTH_TEST);
				glDepthFunc(GL_GREATER);
				break;
			case DepthFunction::GREATER_THAN_OR_EQUAL:
				glEnable(GL_DEPTH_TEST);
				glDepthFunc(GL_GEQUAL);
				break;
			}
		}

		if (force || m_Context != nullptr && m_Context->frontFace != this->frontFace) {
			switch (frontFace) {
			case FrontFace::CLOCKWISE:
				glFrontFace(GL_CW);
				break;
			case FrontFace::COUNTER_CLOCKWISE:
				glFrontFace(GL_CCW);
				break;
			}
		}

		m_Context = this;
	}
	
	void OpenGlContext::forceMakeCurrent() const {
		makeCurrent(true);
	}


	OpenGlContext OpenGlContext::getCurrent() {
		return *m_Context;
	}
}