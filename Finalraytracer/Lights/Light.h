#ifndef __LIGHT__
#define __LIGHT__

#include "Utilities/Vector3D.h"
#include "Color.h"
#include "Utilities/Point3D.h"


class Light
{
public:
    Point3D origin;
    Vector3D direction;
    Color color;

public:
    Light(void);
    Light(const Point3D& origin, const Vector3D& direction);
    Light(const Point3D& origin, const Vector3D& direction, const Color& color);
    Light operator=(const Light& l);
    ~Light();
    void normalize();
};

#endif