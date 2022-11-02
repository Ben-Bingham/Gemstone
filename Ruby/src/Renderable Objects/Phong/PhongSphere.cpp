#include "PhongSphere.h"

#include "Geometry/SphereGeometry.h"

namespace Ruby {
	PhongSphere::PhongSphere(PhongMaterial& mat, unsigned int NumberOfSections, unsigned int NumberOfStacks)
		: PhongRenderable(phongRenderableInit(mat, NumberOfSections, NumberOfStacks)), numberOfSections(NumberOfSections), numberOfStacks(NumberOfStacks) {

	}

	PhongRenderable PhongSphere::phongRenderableInit(PhongMaterial& mat, unsigned int numberOfSections, unsigned int numberOfStacks) {
		SphereGeometry sphere{ numberOfStacks, numberOfSections };

		return PhongRenderable(sphere.getVerticies(true, true), sphere.getIndicies(), mat);
	}
}