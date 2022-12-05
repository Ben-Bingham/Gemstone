#include "Mesh.h"

namespace Ruby {
	Mesh::Mesh()
		: m_Vertices(), m_Indices() {
		
	}

	Mesh::Mesh(Shape shape)
		: m_Vertices(initVertFromShape(shape)), m_Indices(initIndFromShape(shape)) {
		
	}

	Vertices Mesh::initVertFromShape(Shape shape) const {
		switch (shape) {
		case Shape::CUBE: break;
		case Shape::SPHERE: break;
		case Shape::PLANE: break;
		}
		return {};
	}

	Indices Mesh::initIndFromShape(Shape shape) const {
		return {};
	}
}