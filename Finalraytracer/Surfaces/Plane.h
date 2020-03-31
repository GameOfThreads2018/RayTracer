#ifndef  __PLANE__
#define __PLANE__
#include "Utilities/Point3D.h"
#include "Utilities/Normal.h"
#include "Utilities/Ray.h"
#include "Surface.h"
class Plane : public Surface
{
private:
	Point3D point;
	float d;
	Normal normal;
public:
	Plane();
	Plane(const Point3D _point, const Normal _normal);
	~Plane();
	virtual bool hit(Ray& ray);
	void setPoint(Point3D _point);
	void setNormal(Normal _normal);
	Normal getNormal() const;
	Point3D getPoint() const;
};
#endif
