#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

#include "Vector.h"
#include "object.h"
#include "triangleMesh.h"
#include "ray.h"

/*
    The Triangle class stores a pointer to a mesh and an index into its
    triangle array. The mesh stores all data needed by this Triangle.
*/
class Triangle : public Object
{
public:
    Triangle() {}
    virtual ~Triangle() {}

    inline void SetIndex(unsigned int i) {m_index = i;}
    inline void SetMesh(TriangleMesh* m) {m_mesh = m;}

    virtual void RenderGL();
    virtual bool IntersectLocal (HitInfo& result, const Ray& ray,
                            float tMin = MIRO_TMIN, float tMax = MIRO_TMAX);
    
    // functions for getting vertices
    Vector3 vertA(){
        TriangleMesh::TupleI3 m_VIndices =  m_mesh->GetVIndices()[m_index];
        return m_mesh->GetVertices()[m_VIndices.x];
    }

    Vector3 vertB(){
        TriangleMesh::TupleI3 m_VIndices =  m_mesh->GetVIndices()[m_index];
        return m_mesh->GetVertices()[m_VIndices.y];
    }

    Vector3 vertC(){
        TriangleMesh::TupleI3 m_VIndices =  m_mesh->GetVIndices()[m_index];
        return m_mesh->GetVertices()[m_VIndices.z];
    }

    // bounding box
    virtual BoundingBox getLocalBoundingBox();

protected:

    TriangleMesh* m_mesh;
    unsigned int m_index;
};

#endif
