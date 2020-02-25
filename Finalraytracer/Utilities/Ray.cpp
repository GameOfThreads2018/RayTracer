#include <math.h>
#include "Ray.h"

Ray::Ray(void)
{
	direction = Vector3D();
	origin = Point3D();
}

Ray::Ray(const Point3D& _origin, const Vector3D& _direction)
{
	origin = _origin;
	direction = _direction;
}

Ray::~Ray()
{}

void Ray::normalize(void)
{
	double mag = sqrt(direction.lenSquared);
	direction /= mag;
}