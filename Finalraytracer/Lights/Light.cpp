#include "Light.h"

Light::Light()
{
	origin = Point3D();
	direction = Vector3D();
	color = Color();
}

Light::Light(Point3D _origin, Vector3D _direction)
{
	origin = _origin;
	direction = _direction;
	color = Color();
}

Light::Light(Point3D _origin, Vector3D _direction, Color _color) 
{
	origin = _origin;
	direction = _direction;
	color = _color;
}

Light::Light(const Light& l) {
	origin = l.origin;
	direction = l.direction;
	color = l.color;
}

Light::~Light(void) {}



