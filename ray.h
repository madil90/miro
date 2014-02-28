#ifndef __RAY_H__
#define __RAY_H__

#include "Vector.h"

class Ray
{
public:
    enum RayType{
        DIRECT,
        REFLECTION,
        REFRACTION,
        SHADOW,
        INDIRECT
    };

    Vector3 o,      //!< Origin of ray
            d;      //!< Direction of ray
    RayType t;      //!< Type of ray
    int rayId;      //!< for mail boxing

    Ray() : o(), d(Vector3(0.0f,0.0f,1.0f)) , rayId(-1)
    {
        // empty
    }

    Ray(const Vector3& o, const Vector3& d, const RayType tt) : o(o), d(d) , t(tt) , rayId(-1)
    {
        // empty
    }

    Ray(const Vector3& o, const Vector3& d, const RayType tt, int ray_id) : o(o), d(d) , t(tt) , rayId(ray_id)
    {
        // empty
    }
};


//! Contains information about a ray hit with a surface.
/*!
    HitInfos are used by object intersection routines. They are useful in
    order to return more than just the hit distance.
*/
class HitInfo
{
public:
    Vector3 color;                      //!< The color at the hit point
    float t;                            //!< The hit distance
    Vector3 P;                          //!< The hit point
    Vector3 N;                          //!< Shading normal vector
    class Material* material;           //!< Material of the intersected object

    //! Default constructor.
    explicit HitInfo(const Vector3& color = Vector3(),
                     float t = 0.0f,
                     const Vector3& P = Vector3(),
                     const Vector3& N = Vector3(0.0f, 1.0f, 0.0f)) :
        color(color), t(t), P(P), N(N), material (0)
    {
        // empty
    }
};

Ray Transform_Ray(const Ray& ray, Matrix4x4& mat);
void TransformHitInfo(HitInfo& result,Matrix4x4 mat);

#endif
