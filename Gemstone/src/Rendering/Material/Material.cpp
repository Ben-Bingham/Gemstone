#include "pch.h"
#include "Material.h"

#include "Materials/DefaultMaterial.h"
#include "Materials/SimpleMaterial.h"

namespace Gem {
	Material::Material(const Ptr<IMaterial>& material)
		: iMaterial(material) { }

	Material::Material(const Image& diffuse, const Image& specular)
		: iMaterial(CreatePtr<DefaultMaterial>(diffuse, specular)) { }

	Material::Material(const Colour& colour)
		: iMaterial(CreatePtr<SimpleMaterial>(colour)) { }
}