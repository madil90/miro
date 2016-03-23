#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <list>
#include "miro.h"
#include "material.h"
#include "bbox.h"

typedef std::list<class Object*> ObjectList;

class Object
{
public:
    Object() ;
    virtual ~Object() { delete m_material;}

    // setters
    void SetMaterial (Material* m) {m_material = m;}
    void SetTransformation (Matrix4x4 m_transform);
    void SetVelocity(Vector3 velocity) {m_velocity = velocity;}

    // getters
    Material* getMaterial()  {return m_material;}
    Matrix4x4 getTransformation() { return m_xTransform;}
    Matrix4x4 getNormalTransformation() {return m_xTransformNorm;}

    // helper functions
    virtual bool Refine(ObjectList& objects) {return false;}
    virtual void RenderGL() {}
    virtual void PreCalc() ;


    // intersection functions
    virtual bool IntersectLocal (HitInfo& result, const Ray& ray,
                            float tMin = MIRO_TMIN, float tMax = MIRO_TMAX) ;
    virtual bool Intersect (HitInfo& result, const Ray& ray,
                            float tMin = MIRO_TMIN, float tMax = MIRO_TMAX) ;
    virtual bool Intersect (HitInfo& result, const Ray& ray, 
                            Matrix4x4 transform, Matrix4x4 transformInv, Matrix4x4 transformNorm,
                            float tMin = MIRO_TMIN, float tMax = MIRO_TMAX) ;

    // bounding box functions
    virtual BoundingBox getLocalBoundingBox() {return BoundingBox();}
    virtual BoundingBox getBoundingBox() {return box;}
    virtual bool intersectBox(BoundingBox& target) {return box.intersects(target);}

    // object tagging
    virtual void clearTAG();
    virtual void setTAG(int tag);
    virtual int getTAG();

protected:
    Material* m_material;

    // velocity for motion blur
    Vector3 m_velocity;

    // These two are used to change form local to global co-ordinates and normal transform too
    Matrix4x4 m_xTransform, m_xTransformInv, m_xTransformNorm;

    // bounding box for bsp tree
    BoundingBox box;

    // ray id for mailboxing
    int rayId;
};

#endif
