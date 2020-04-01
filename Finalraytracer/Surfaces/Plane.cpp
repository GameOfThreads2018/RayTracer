#include <math.h>
#include "Plane.h"
#include "Surface.h"

Plane::Plane()
{
}

Plane::Plane(const Point3D _point, const Normal _normal)
{
	setPoint(_point);
	setNormal(_normal);
}

Plane::~Plane()
{
}

void Plane::setNormal(const Normal _normal)
{
	normal = _normal;
}

void Plane::setPoint(const Point3D _point)
{
	point = _point;
}

Normal Plane::getNormal() const
{
	return normal;
}

Point3D Plane::getPoint() const
{
	return point;
}

bool Plane::hit(Ray& ray)
{
	float d = (point-ray.origin).dotProduct(normal)/(normal.dotProduct(ray.direction));
	if(d < .00001F)
	{
		return true;
	}
	return false;
}