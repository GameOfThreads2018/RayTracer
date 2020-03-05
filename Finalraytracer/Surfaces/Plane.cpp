#include "Plane.h"
Plane::Plane()
{
}

Plane::Plane(const Point3D _point, const Normal& _normal, const float _a)
{
	setPoint(_point);
	setNormal(_normal);
	a =_a;
}

Plane::~Plane()
{
}

void Plane::setNormal(const Normal normal)
{
	this->normal = normal;
}

void Plane::setPoint(const Point3D point)
{
	this->point = point;
}

Normal Plane::getNormal() const
{
	return this->normal;
}

Point3D Plane::getPoint()
{
	return this->point;
}

bool Plane::hit(Ray& ray)
{
	int d = (point-ray.origin).dotProduct(normal)/(normal.dotProduct(ray.direction));
	if(d > .00001F)
	{
		return true;
	}
	return false;
}