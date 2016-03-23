#ifndef _BOUNDING_BOX_
#define _BOUNDING_BOX_

#include "Vector.h"
#include "miro.h"
#include <limits>
#include <assert.h>

class Triangle;
class Ray;

class BoundingBox{
public:
	BoundingBox()
	{
		minimum[0] = std::numeric_limits<float>::max();
		minimum[1] = std::numeric_limits<float>::max();
		minimum[2] = std::numeric_limits<float>::max();
		maximum[0] = -std::numeric_limits<float>::max();
		maximum[1] = -std::numeric_limits<float>::max();
		maximum[2] = -std::numeric_limits<float>::max();
	}
	BoundingBox(Vector3 min, Vector3 max);

	void RenderGL();

	Vector3 Max();
	Vector3 Min();
	Vector3 parameter(int index)
	{
		assert(index<2);
		if (index==0)
			return minimum;
		else
			return maximum;
	}
	
	bool intersect(const Ray& ray,float &tmin,float &tmax,float t0=MIRO_TMIN,float t1=MIRO_TMAX);

	void transformBox(Matrix4x4& mat);

	void expand(Vector3& point);
	void expand(BoundingBox box);

	bool intersects(const BoundingBox &target) const;

	float Area();

protected:
	Vector3 minimum;
	Vector3 maximum;
};

#endif