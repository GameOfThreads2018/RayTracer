#ifndef __NORMAL__
#define __NORMAL__
#include "Vector3D.h"
class Normal
{
public: float x, y, z;
public:
	Normal(void);
	Normal(float x, float y, float z);
	~Normal(void);

	void normalize(void);

	inline Normal operator-(void) const
	{
		return Normal(-x, -y, -z);
	}
	inline Normal operator+(const Normal& n) const
	{
		return Normal(x + n.x, y + n.y, z + n.z);
	}
	inline Normal& operator+= (const Normal& n)
	{
		x += n.x;
		y += n.y;
		z += n.z;
		return *this;
	}
	inline Normal operator* (const float a) const
	{
		return Normal(a * x, a * y, a * z);
	}
	inline float dotProduct(const Vector3D& v)
	{
		return x * v.x + y * v.y + z * v.z;
	}
	inline float lenSquared()
	{
		return x * x + y * y + z * z;
	}
};
#endif // !__NORMAL__