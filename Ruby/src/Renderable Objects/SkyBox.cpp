#include "SkyBox.h"

namespace Ruby {
	void SkyBox::render(const Malachite::Matrix4f& view, const Malachite::Matrix4f& projection) const {
		m_Material->use(m_ModelMatrix, view, projection);
		m_VAO.bind();

		glDepthMask(GL_FALSE); //TODO make a GLContext class that has a lot of flags for all these things
		glCullFace(GL_FRONT);
		glDepthFunc(GL_LEQUAL);

		glDrawElements(GL_TRIANGLES, m_EBO.getNumberOfIndices(), GL_UNSIGNED_INT, 0);

		glDepthFunc(GL_LESS);
		glCullFace(GL_BACK);
		glDepthMask(GL_TRUE);
	}

	CubeGeometryData SkyBox::m_SkyBoxGeometryData{ };
}