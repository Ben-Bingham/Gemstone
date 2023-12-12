#include "pch.h"
#include "Rendering/Material/Material.h"

#include "Rendering/Material/Materials/DefaultMaterial.h"
#include "Rendering/Material/Materials/SimpleMaterial.h"

namespace Gem {
	Material::Material(const Ptr<IMaterial>& material)
		: iMaterial(material) { }

	//Material::Material(const Image& diffuse, const Image& specular)
	//	: iMaterial(CreatePtr<DefaultMaterial>(diffuse, specular)) { }

	//Material::Material(const Colour& colour)
	//	: iMaterial(CreatePtr<SimpleMaterial>(colour)) { }
}