#ifndef __POINT_3D__
#define __POINT_3D__

#include "Vector3D.h"

class Point3D
{
public:
	double x, y, z;
public:
	Point3D(void);
	Point3D(const double a);
	Point3D(double x, double y, double z);
	Point3D(const Point3D& p);
	~Point3D(void);

	double distance(void);

	inline double dotProduct(const Point3D& p)
	{
		return x * p.x + y * p.y + z * p.z;
	}

	inline double dotProduct(const Vector3D& v)
	{
		return v.x * x + v.y * y + v.z * z;
	}

	inline Point3D operator+(const Point3D& p)
	{
		return Point3D(x + p.x, y + p.y, z + p.z);
	}

	inline Point3D operator-(const Point3D& p)
	{
		return Point3D(x - p.x, y - p.y, z - p.z);
	}

	inline Point3D operator*(const double a)
	{
		return Point3D(x * a, y * a, z * a);
	}

	inline Point3D operator+(const Vector3D& v)
	{
		return Point3D(x + v.x, y + v.y, z + v.z);
	}

	inline Point3D operator-(const Vector3D& v)
	{
		return Point3D(x - v.x, y - v.y, z - v.z);
	}
	inline double lenSquared(void)
	{
		return x * x + y * y + z * z;
	}
};
#endif