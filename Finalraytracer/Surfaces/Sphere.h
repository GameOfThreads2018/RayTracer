#ifndef __SPHERE__
#define __SPHERE__

#include "Utilities\Point3D.h"
#include "Utilities\Vector3D.h"
#include "Surface.h"
class Sphere : public Surface
{
private:
	float radius, t;
	Point3D center;

public:
	Sphere();
	Sphere(const Point3D center, const float radius);
	~Sphere();
	virtual bool hit(Ray& ray);
	void setRadius(float _radius);
	void setCenter(Point3D center);
	void setT(float _t);
	float getT();
	float getRadius() const;
	Point3D getCenter() const;
	Vector3D calculateInersectPoint(Ray& ray);
	Vector3D calculateNormal(Ray& ray);

};
#endif