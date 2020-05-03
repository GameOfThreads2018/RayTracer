#include "Sphere.h"
#include "Surface.h"
#include "Utilities/Point3D.h"
#include "Utilities/Ray.h"

Sphere::Sphere()
{
	center = Point3D();
	radius = 1.0F;
	t = 0.0F;
}

Sphere::Sphere(const Point3D center, const float radius)
{
	setCenter(center);
	setRadius(radius);
	t = 0.0F;
}

Sphere::~Sphere()
{
}

bool Sphere::hit(Ray& ray)
{
	float a, b, c;
	a = ray.getDirection().dotProduct(ray.getDirection());
	b = 2 * (ray.getOrigin()-center).dotProduct(ray.getDirection());
	c = (ray.getOrigin()-center).dotProduct(ray.getOrigin()-center) - radius*radius;
	float discrim = b*b - 4*a*c;
	float one = (float) ((-b-sqrt(discrim ))/(2*a));
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

Vector3D Sphere::calculateInersectPoint(Ray& ray)
{
	return ray.getDirection() * t + Vector3D(ray.getOrigin().x, ray.getOrigin().y, ray.getDirection().z);
}

Vector3D Sphere::calculateNormal(Ray& ray)
{
	Vector3D normal = calculateInersectPoint(ray) - Vector3D(this->getCenter().x, this->getCenter().y, this->getCenter().z);
	return normal;
} 
