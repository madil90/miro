#ifndef __TRIANGLE_MESH_H__
#define __TRIANGLE_MESH_H__

#include "Vector.h"
#include "object.h"

class TriangleMesh : public Object
{
public:
    TriangleMesh();
    virtual ~TriangleMesh();

    // load from an OBJ file
    bool Load(char* file, char* group="all");

    // for single triangles
    void CreateSingleTriangle();
    inline void SetV1(const Vector3& v) { m_pVertices[0] = v; }
    inline void SetV2(const Vector3& v) { m_pVertices[1] = v; }
    inline void SetV3(const Vector3& v) { m_pVertices[2] = v; }
    inline void SetN1(const Vector3& n) { m_pNormals[0] = n; }
    inline void SetN2(const Vector3& n) { m_pNormals[1] = n; }
    inline void SetN3(const Vector3& n) { m_pNormals[2] = n; }

    void ComputeNormals();

    struct TupleI3
    {
        unsigned int x, y, z;
    };

    struct VectorR2
    {
        float x, y;
    };

    inline Vector3* GetVertices() { return m_pVertices; }
    inline Vector3* GetNormals() { return m_pNormals; }
    inline TupleI3* GetVIndices() { return m_pVertexIndices; }
    inline TupleI3* GetNIndices() { return m_pNormalIndices; }
    inline int GetNumTris() { return m_iNumTris; }

    virtual bool Refine(ObjectList& objects);
    virtual void RenderGL();
    virtual bool Intersect (HitInfo& result, const Ray& ray,
                            float tMin = MIRO_TMIN, float tMax = MIRO_TMAX);
protected:
    void LoadObj(FILE* fp, char* group);

    Vector3* m_pNormals;
    Vector3* m_pVertices;
    VectorR2* m_pTexCoords;

    TupleI3* m_pNormalIndices;
    TupleI3* m_pVertexIndices;
    TupleI3* m_pTexCoordIndices;
    unsigned int m_iNumTris;
};


#endif
