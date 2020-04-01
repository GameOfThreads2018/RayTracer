#pragma once
#ifndef __SURFACE__
#define __SURFACE__
#include "Utilities/Ray.h"
class Surface {

public:
	Surface();
	virtual ~Surface();
	virtual bool hit(Ray& ray);
};
#endif // !__SURFACE__
