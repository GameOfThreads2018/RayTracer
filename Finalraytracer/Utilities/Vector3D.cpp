#include <math.h>
#include "Vector3D.h"

Vector3D::Vector3D() {
	x = 0.0;
	y = 0.0;
	z = 0.0;
}

Vector3D::Vector3D(const float a)
{
	x = a;
	y = a;
	z = a;
}

Vector3D::Vector3D(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

Vector3D::Vector3D(const Vector3D& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
}
Vector3D::~Vector3D()
{}

float Vector3D::length(void)
{
	return sqrt(this->lenSquared());
}

void Vector3D::normalize(void)
{
	const float magnitude = length();
	x /= magnitude;
	y /= magnitude;
	z /= magnitude;
}
