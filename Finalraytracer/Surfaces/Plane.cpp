#include <math.h>
#include "Plane.h"
#include "Surface.h"

Plane::Plane()
{
	point = Point3D();
	normal = Normal();
	d = 0;
}

Plane::Plane(const Point3D _point, const Normal _normal)
{
	setPoint(_point);
	setNormal(_normal);
	d = 0;
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

float Plane::getD()
{
	return d;
}

bool Plane::hit(Ray& ray)
{
	 d = (point-ray.getOrigin()).dotProduct(normal)/(normal.dotProduct(ray.getDirection()));

	if(d > .00001F)
	{
		return true;
	}

	return false;
}

Vector3D Plane::calculateIntersectPoint(Ray& ray)
{
	return ray.getDirection() * d + Vector3D(ray.getOrigin().x, ray.getOrigin().y, ray.getOrigin().z);
}