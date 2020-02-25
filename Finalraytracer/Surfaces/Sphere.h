#ifndef __SPHERE__
#define __SPHERE__
#include "Point3D.h"
#include "Normal.h"
#include "Ray.h"
class Sphere : public Surface
{
private:
	float radius, a, t;
	Point3D center;

public:
	Sphere();
	Sphere(const Point3D center, const float radius, const float a);
	virtual bool hit(Ray& ray);
	void setRadius(float _radius);
	void setCenter(Point3D center);
	void setT(float _t);
	float getT();
	float getRadius() const;
	Point3D getCenter() const;

};