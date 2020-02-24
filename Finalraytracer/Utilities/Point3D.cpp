
#include <math.h>
#include "Point3D.h"

Point3D::Point3D(void) {
	x = 0.0;
	y = 0.0;
	z = 0.0;
}

Point3D::Point3D(const double a)
{
	x = a;
	y = a;
	z = a;
}

Point3D::Point3D(double _x, double _y, double _z)
{
	x = _x;
	y = _y;
	z = _z;
}

Point3D::Point3D(const Point3D& p)
{
	x = p.x;
	y = p.y;
	z = p.z;
}

Point3D::~Point3D(void)
{}


double Point3D::distance(void)
{
	return sqrt(x * x + y * y + z * z);
}