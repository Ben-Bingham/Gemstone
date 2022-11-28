#include "SkyBox.h"

namespace Ruby {
	void SkyBox::render(const Malachite::Matrix4f& view, const Malachite::Matrix4f& projection) const {
		m_Material->use();
		m_VAO.bind();

		Malachite::Matrix4f viewMat = Malachite::Matrix4f{
			Malachite::Vector4f{view.row1.x, view.row1.y, view.row1.z, 0.0f},
			Malachite::Vector4f{view.row2.x, view.row2.y, view.row2.z, 0.0f},
			Malachite::Vector4f{view.row3.x, view.row3.y, view.row3.z, 0.0f},
			Malachite::Vector4f{0.0f, 0.0f, 0.0f, 1.0f}
		};

		Malachite::Matrix4f viewProjection = viewMat * projection;
		ShaderProgram::upload("viewProjection", viewProjection);


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