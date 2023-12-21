#include "Rendering/Materials/Material.h"
#include "Rendering/Materials/SolidColour.h"

namespace Gem {
	Material::Material(const Ptr<BaseMaterial>& material)
		: material(material) {}

	//Material::Material(const Colour& colour)
	//	: material(CreatePtr<SolidColour_>(colour)) { }

	//Material::Material(const Image& diffuse, const Image& specular) {}
}