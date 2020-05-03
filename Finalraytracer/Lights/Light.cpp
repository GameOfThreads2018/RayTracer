#include "Light.h"
#include "Color.cpp"

Light::Light()
{
	origin = Point3D();
	direction = Vector3D();
	color = Color();
}

Light::Light(const Point3D& _origin, const Vector3D& _direction)
{
	origin = _origin;
	direction = _direction;
	color = Color();
}

Light::Light(const Point3D& _origin, const Vector3D& _direction, const Color& _color) 
{
	origin = _origin;
	direction = _direction;
	color = _color;
}

Light Light::operator=(const Light& l)
{
	origin = l.origin;
	direction = l.direction;
	color = l.color;
	return *(this);
}

Light::~Light(void) {}

void Light::normalize()
{
	direction.normalize();
}



