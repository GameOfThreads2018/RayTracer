#ifndef __POINT_3D__
#define __POINT_3D__

#include "Vector3D.h"
#include "Normal.h"

class Point3D
{
public:
	float x, y, z;
public:
	Point3D(void);
	Point3D(const float a);
	Point3D(float x, float y, float z);
	Point3D(const Point3D& p);
	~Point3D(void);

	float distance(void);

	inline float dotProduct(const Point3D& p)
	{
		return x * p.x + y * p.y + z * p.z;
	}

	inline float dotProduct(const Vector3D& v)
	{
		return v.x * x + v.y * y + v.z * z;
	}
	inline float dotProduct(const Normal& n)
	{
		return n.x * x + n.y * y + n.z * z;
	}
	inline Point3D operator+(const Point3D& p)
	{
		return Point3D(x + p.x, y + p.y, z + p.z);
	}

	inline Point3D operator-(const Point3D& p)
	{
		return Point3D(x - p.x, y - p.y, z - p.z);
	}

	inline Point3D operator*(const float a)
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
	inline float lenSquared(void)
	{
		return x * x + y * y + z * z;
	}
};
#endif