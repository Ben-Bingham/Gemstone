#include "Material.h"

namespace Ruby {
	Material::Material(ShaderProgram& program)
		: m_Program(&program) {
	
	}

	void Material::end() { }
}