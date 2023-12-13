#include "ShaderLibrary.h"

namespace Ruby {
	ShaderLibrary& ShaderLibrary::get() {
		static ShaderLibrary instance;

		return instance;
	}
}