#include "Sphere.h"

Sphere::Sphere()
{
}

Sphere::Sphere(const Point3D center, const float radius, const float a)
{
	setCenter(center);
	setRadius(radius);
	this->a = a;
}

Sphere::~Sphere()
{
}

bool Sphere::hit(Ray& ray)
{
	float a, b, c;
	a = ray.direction.dotProduct(ray.direction);
	b = 2 * (ray.origin-center).dotProduct(ray.direction);
	c = (ray.origin-center).dot(ray.origin-center) - radius*radius;
	float discrim = b*b - 4*a*c;
	float one;
	one = (float) ((-b-Math.sqrt(discrim ))/(2*a));
	if(one > .00001F)
	{
		setT(one);
	}

	if(discrim >= 0)
	{
		return true;
	}

	else 
	{
		return false;
	}
}

void Sphere::setRadius(const float _radius)
{
	this->radius = _radius;
}

void Sphere::setCenter(const Point3D _center)
{
	this->center = _center;
}

float Sphere::getRadius() const
{
	return this->radius;
}

Point3D Sphere::getCenter() const
{
	return this->center;
}

void Sphere::setT(float _t)
{
	this->t =_t;
}

float Sphere::getT()
{
	return this->t;
}


