#ifndef __RAY__
#define __RAY__

#include "Vector3D.h"
#include "Point3D.h"

class Ray {
private:
    Point3D origin;
    Vector3D direction;
public:
    Ray(void);
    Ray(const Point3D &origin, const Vector3D &direction);
    ~Ray(void);

    void normalize(void);
    Vector3D getDirection();
    Point3D getOrigin();
};
#endif // !__RAY__


