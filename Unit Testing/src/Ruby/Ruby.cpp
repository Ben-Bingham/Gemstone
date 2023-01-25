#include "Ruby.h"

#include "Geometry/Shape.h"

void ruby() {
	using namespace Celestite;

	Ptr<Ruby::Sphere> sphere1 = CreatePtr<Ruby::Sphere>();
	Ptr<Ruby::Sphere> sphere2 = CreatePtr<Ruby::Sphere>();
	assert(Equal(sphere1, sphere2)); // Two spheres are equal


	Ptr<Ruby::Cube> cube1 = CreatePtr<Ruby::Cube>();
	Ptr<Ruby::Cube> cube2 = CreatePtr<Ruby::Cube>();
	assert(Equal(cube1, cube2)); // Two cubes are equal


	Ptr<Ruby::Plane> plane1 = CreatePtr<Ruby::Plane>();
	Ptr<Ruby::Plane> plane2 = CreatePtr<Ruby::Plane>();
	assert(Equal(plane1, plane2)); // Two spheres are equal


	assert(!Ruby::Equal(cube1, sphere1)); // Two different objects are not equal
}
