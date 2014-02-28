#ifndef __INSTANCE_H__
#define __INSTANCE_H__

#include "Vector.h"
#include "object.h"

class Instance : public Object
{
public:
    Instance();
    ~Instance();

    void SetGeometry(Object* g, const Matrix4x4& ctm);
    virtual void RenderGL();
    virtual bool Intersect (HitInfo& result, const Ray& ray,
                            float tMin = MIRO_TMIN, float tMax = MIRO_TMAX);

protected:
    Matrix4x4 m_xform, m_xformInv;
    Object* m_geometry;
};

#endif
