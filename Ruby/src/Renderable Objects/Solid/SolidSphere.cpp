#include "SolidSphere.h"

#include "Renderable Objects/Geometry/SphereGeometry.h"

namespace Ruby {
	SolidSphere::SolidSphere(SolidMaterial& mat, unsigned int NumberOfSections, unsigned int NumberOfStacks)
		: SolidRenderable(solidRenderableInit(mat, NumberOfSections, NumberOfStacks)), numberOfSections(NumberOfSections), numberOfStacks(NumberOfStacks) {

	}

	SolidRenderable SolidSphere::solidRenderableInit(SolidMaterial& mat, unsigned int numberOfSections, unsigned int numberOfStacks) {
		SphereGeometry sphere{ numberOfStacks, numberOfSections };

		return SolidRenderable(sphere.getVerticies(false, false), sphere.getIndicies(), mat);
	}
}