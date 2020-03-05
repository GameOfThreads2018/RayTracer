#pragma once
#ifndef __SURFACE__
#define __SURFACE__
#include "Utilities/Ray.h"
class Surface {
	Surface(void);
	virtual ~Surface(void);
	virtual bool hit(Ray& ray);
};
#endif // !__SURFACE__
