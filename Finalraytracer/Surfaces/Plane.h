#ifndef  __PLANE__
#define __PLANE__
#include "Point3D.h"
#include "Normal.h"
#include "Ray.h"
class Plane : public Surface
{
private:
	Point3D point;
	float a, d;
	Normal normal;
public:
	Plane();
	Plane(const Point3D point ,const Normal normal, const float a);
	virtual bool hit(Ray& ray);
	void setPoint(Point3D _point);
	void setNormal(Normal _normal);
	Normal getNormal() const;
	Point3D getPoint() const;
};
#endif
