#ifndef __LIGHT__
#define __LIGHT__

#include "Vector3D.h"
#include "Color.h"
#include "Point3D.h"


class Light
{
public:
    Point3D origin;
    Vector3D direction;
    Color color;

public:
    Light(void);
    Light(Point3D origin, Vector3D direction);
    Light(Point3D origin, Vector3D direction, Color color);
    Light(const Light& l);
};

#endif