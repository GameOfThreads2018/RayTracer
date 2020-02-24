#ifndef __VECTOR_3D__
#define __VECTOR_3D__

class Vector3D
{
public:
	double x, y, z;
public:
	Vector3D(void);
	Vector3D(double a);
	Vector3D(double _x, double _y, double _z);
	Vector3D(const Vector3D& v);
	~Vector3D(void);

	Vector3D operator+(const Vector3D& vec);
	Vector3D operator-(const Vector3D& vec);
	Vector3D operator*(const double a);
	Vector3D operator/(const double a);
	Vector3D operator+=(const Vector3D& vec);
	Vector3D operator-=(const Vector3D& vec);
	Vector3D operator*=(const double a);
	Vector3D operator/=(const double a);
	double dotProduct(const Vector3D& vec);
	double length(void);
	void normalize(void);

	inline Vector3D operator+(const Vector3D& vec)
	{
		return (Vector3D(x + vec.x, y + vec.y, z + vec.z));
	}

	inline Vector3D operator-(const Vector3D& vec)
	{
		return (Vector3D(x - vec.x, y - vec.y, z - vec.z));
	}

	inline Vector3D operator*(const double a)
	{
		return (Vector3D(x * a, y * a, z * a));
	}

	inline Vector3D operator/(const double a)
	{
		return (Vector3D(x / a, y / a, z / a));
	}

	inline Vector3D operator+=(const Vector3D& vec)
	{
		x += vec.x; y += vec.y; z += vec.z;
		return (*this);
	}

	inline Vector3D operator-=(const Vector3D& vec)
	{
		x -= vec.x; y -= vec.y; z -= vec.z;
		return (*this);
	}

	inline Vector3D operator+=(const Vector3D& vec)
	{
		x += vec.x; y += vec.y; z += vec.z;
		return (*this);
	}

	inline Vector3D operator*=(const double a)
	{
		x *= a; y *= a; z *= a;
		return (*this);
	}

	inline Vector3D operator/=(const double a)
	{
		x /= a; y /= a; z /= a;
		return (*this);
	}

	inline double dotProduct(const Vector3D& vec)
	{
		return (x * vec.x + y * vec.y + z * vec.z);
	}
};
#endif
