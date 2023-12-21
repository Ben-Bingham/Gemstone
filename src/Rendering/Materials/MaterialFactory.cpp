#include "Rendering/Materials/MaterialFactory.h"

namespace Gem {
	SolidColour CreateMaterial(const Colour& colour) {
		return CreatePtr<SolidColour_>(colour);
	}
}