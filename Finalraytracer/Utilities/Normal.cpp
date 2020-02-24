#include <math.h>
#include "Normal.h"

Normal::Normal(void)
{
	x = 0;
	y = 0;
	z = 0;
}

Normal::Normal(double _x, double _y, double _z)
{
	x = _x;
	y = _y;
	z = _z;
}

Normal::~Normal()
{}

void Normal::normalize()
{
	double mag = sqrt(x * x + y * y + z * z);
	x /= mag;
	y /= mag;
	z /= mag;
}