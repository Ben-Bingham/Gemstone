#include "MaterialData.h"

namespace Ruby {
	MaterialData::MaterialData(ShaderProgram& program)
		: m_Program(&program) {
	
	}

	void MaterialData::end() { }
}