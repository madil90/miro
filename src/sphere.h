#ifndef __SPHERE_H__
#define __SPHERE_H__

#include "Vector.h"
#include "object.h"
#include "ray.h"
#include "bbox.h"

class Sphere : public Object
{
public:
    Sphere();
    ~Sphere();

    void SetCenter(const Vector3& v) { m_vCenter = v; }
    void SetRadius(const float f) { m_fRadius = f; }

    inline Vector3& GetCenter() { return m_vCenter; }
    inline float GetRadius() { return m_fRadius; }

    virtual void RenderGL();
    virtual bool IntersectLocal (HitInfo& result, const Ray& ray,
                            float tMin = MIRO_TMIN, float tMax = MIRO_TMAX);

    // bounding box
    virtual BoundingBox getLocalBoundingBox();

protected:
    Vector3 m_vCenter;
    float m_fRadius;
};

#endif
