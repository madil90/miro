#ifndef _SQUARE_H_
#define _SQUARE_H_

#include "Vector.h"
#include "ray.h"
#include "object.h"

class Square : public Object
{
public:
	Square();
	~Square() {}

	// set normal and center
	void SetCenter(Vector3 center) { m_vCenter = center;}
	
	// getters
	Vector3 getCenter(){return m_vCenter;}

	// ovverride functions
	virtual void RenderGL();
    virtual bool IntersectLocal (HitInfo& result, const Ray& ray,
                            float tMin = MIRO_TMIN, float tMax = MIRO_TMAX);

    // bounding box
    virtual BoundingBox getLocalBoundingBox();

protected:
	Vector3 m_vCenter;
};

#endif
