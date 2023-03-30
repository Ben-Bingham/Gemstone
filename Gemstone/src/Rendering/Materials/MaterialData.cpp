#include "pch.h"
#include "MaterialData.h"

namespace Gem {
	MaterialData::MaterialData(ShaderProgram& program)
		: m_Program(&program) {
	
	}

	void MaterialData::end() { }
}