#include <math.h>
#include "Normal.h"

Normal::Normal(void)
{
	x = 0;
	y = 0;
	z = 0;
}

Normal::Normal(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

Normal::~Normal()
{}

void Normal::normalize()
{
	float mag = sqrt(this->lenSquared());
	this* (1 / mag);
}