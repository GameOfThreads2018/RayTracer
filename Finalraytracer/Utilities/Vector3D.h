#ifndef __VECTOR_3D__
#define __VECTOR_3D__

#include "Point3D.h"

class Vector3D
{

public:
	float x, y, z;
public:
	Vector3D();
	Vector3D(float a);
	Vector3D(float _x, float _y, float _z);
	Vector3D(const Vector3D& v);
	~Vector3D();
	float length();
	void normalize();
	Vector3D& operator= (const Vector3D& rhs);

	inline Vector3D operator+(const Vector3D& vec)
	{
		return (Vector3D(x + vec.x, y + vec.y, z + vec.z));
	}

	inline Vector3D operator-(const Vector3D& vec)
	{
		return (Vector3D(x - vec.x, y - vec.y, z - vec.z));
	}

	inline Vector3D operator*(const float a)
	{
		return (Vector3D(x * a, y * a, z * a));
	}

	inline Vector3D operator/(const float a)
	{
		return (Vector3D(x / a, y / a, z / a));
	}

	inline Vector3D operator-=(const Vector3D& vec)
	{
		x -= vec.x; y -= vec.y; z -= vec.z;
		return (*this);
	}

	inline Vector3D operator+=(const Vector3D& vec)
	{
		x += vec.x;
		y += vec.y;
		z += vec.z;
		return (*this);
	}

	inline Vector3D operator*=(const float a)
	{
		x *= a; y *= a; z *= a;
		return (*this);
	}

	inline Vector3D operator/=(const float a)
	{
		x /= a; y /= a; z /= a;
		return (*this);
	}

	inline float dotProduct(const Vector3D& vec)
	{
		return x * vec.x + y * vec.y + z * vec.z;
	}

	inline float lenSquared(void)
	{
		return x * x + y * y + z * z;
	}
};
#endif
